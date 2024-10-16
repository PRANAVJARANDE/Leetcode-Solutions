class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>q1;
        if(a>0)q1.push({a,'a'});
        if(b>0)q1.push({b,'b'});
        if(c>0)q1.push({c,'c'});
        while(!q1.empty())
        {
            auto p1=q1.top();
            q1.pop();
            if(ans.size()>=2 && ans[ans.size()-1]==p1.second && ans[ans.size()-2]==p1.second)
            {
                if(q1.empty())break;
                auto p2=q1.top();
                q1.pop();
                ans+=p2.second;
                if(p2.first-1>0)q1.push({p2.first-1,p2.second});
                q1.push(p1);
            }
            else
            {
                ans+=p1.second;
                if(p1.first-1>0)q1.push({p1.first-1,p1.second});
            }
            
        }
        return ans;
    }
};
