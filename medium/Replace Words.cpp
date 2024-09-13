class Solution {
public:
    class node {
    public:
        bool endd;
        node* next[26];
        node() {
            endd = false;
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };

    node* trie = new node();

    void insertt(const string& s) {
        node* temp = trie;
        for (char c : s) {
            if (temp->next[c - 'a'] == nullptr) {
                temp->next[c - 'a'] = new node();
            }
            temp = temp->next[c - 'a'];
        }
        temp->endd = true;
    }

    bool searchh(const string& s) {
        node* temp = trie;
        for (char c : s) {
            if (temp == nullptr) return false;
            temp = temp->next[c - 'a'];
        }
        return temp != nullptr && temp->endd;
    }

    string replaceWords(vector<string>& dict, string s) 
    {
        for (auto x : dict) 
        {
            insertt(x);
        }

        stringstream ss(s);
        string word,result;

        while (ss >> word) {
            node* temp = trie;
            string root;
            bool found = false;
            for (char c : word) 
            {
                if (temp->next[c - 'a'] == nullptr) break;
                root += c;
                temp = temp->next[c - 'a'];
                if (temp->endd) 
                {
                    found = true;
                    break;
                }
            }

            if (found) 
            {
                result += root + " ";
            } 
            else 
            {
                result += word + " ";
            }
        }

        if (!result.empty()) {
            result.pop_back();
        }
        return result;
    }
};
