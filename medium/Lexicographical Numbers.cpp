// Brute Force
class Solution1 {
public:
    vector<int> lexicalOrder(int n) 
    {
        set<string> s1;
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            s1.insert(to_string(i));
        }
        for(auto x: s1)
        {
            ans.push_back(stoi(x));
            s1.erase(x);
        }
        return ans;
    }
};

//Sort Function 
class Solution2 {
public:

    static bool cmp(int a,int b)return to_string(a)<to_string(b);

    vector<int> lexicalOrder(int n) 
    {
        vector<int> ans;
        for(int i=1;i<=n;i++)ans.push_back(i);
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};

// o(n) time complexity and o(1)space complecxtiy
class Solution {
public:
    void dfs(int curr,int n,vector<int> &ans) 
    {
        if(curr>n)return;
        ans.push_back(curr);
        for (int i=0;i<=9;i++) 
        {
            if(curr*10+i>n)break;
            dfs(curr*10+i,n,ans);
        }
    }

    vector<int> lexicalOrder(int n) 
    {
        vector<int> ans;
        for(int i=1;i<=9;i++) 
        {
            if(i>n)break;
            dfs(i,n,ans);
        }
        return ans;
    }
};

