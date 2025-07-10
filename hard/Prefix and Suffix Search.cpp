class WordFilter {
public:
    class Trie {
    public:
        class Node {
        public:
            int finish;
            vector<Node*> next;
            Node() : finish(-1), next(27, nullptr) {} // 26 letters + '#'
        };

        Node* root;
        Trie() {
            root = new Node();
        }

        int getIndex(char c) {
            if (c == '#') return 26;
            return c - 'a';
        }

        void insert(const string& s, int index) {
            Node* node = root;
            for (char c : s) {
                int idx = getIndex(c);
                if (!node->next[idx]) {
                    node->next[idx] = new Node();
                }
                node = node->next[idx];
                node->finish = index;  
            }
        }

        int search(const string& s) {
            Node* node = root;
            for (char c : s) {
                int idx = getIndex(c);
                if (!node->next[idx]) return -1;
                node = node->next[idx];
            }
            return node->finish;
        }
    };

    Trie trie;

    WordFilter(vector<string>& words) {
        for (int index = 0; index < words.size(); ++index) 
        {
            string word = words[index];
            int len = word.size();
            for (int i = 0; i <= len; ++i) 
            {
                string suffix = word.substr(i);
                string key = suffix + '#' + word;
                trie.insert(key, index);
            }
        }
    }

    int f(string pref, string suff) {
        string key = suff + '#' + pref;
        return trie.search(key);
    }
};
