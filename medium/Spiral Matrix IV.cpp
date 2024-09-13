/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        ListNode*  temp=head;
        if(temp==NULL)return ans;
        int rs=0,cs=0,re=m-1,ce=n-1;
        while(rs<=re && cs<=ce)
        {
            for(int i=cs;i<=ce;i++)
            {
                ans[rs][i]=temp->val;
                temp=temp->next;
                if(temp==NULL)
                {
                    return ans;
                }
            }
            rs++;
            for(int i=rs;i<=re;i++)
            {
                ans[i][ce]=temp->val;
                temp=temp->next;
                if(temp==NULL)
                {
                    return ans;
                }
            }
            ce--;
            for(int i=ce;i>=cs;i--)
            {
                ans[re][i]=temp->val;
                temp=temp->next;
                if(temp==NULL)
                {
                    return ans;
                }
            }
            re--;
            for(int i=re;i>=rs;i--)
            {
                ans[i][cs]=temp->val;
                temp=temp->next;
                if(temp==NULL)
                {
                    return ans;
                }
            }
            cs++;
        }
        return ans;
    }
};
