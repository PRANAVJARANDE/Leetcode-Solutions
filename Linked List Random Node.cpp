class Solution {
public:

    vector<int> v1;

    Solution(ListNode* h) 
    {
        ListNode*temp=h;
        while(temp!=NULL)
        {
            v1.push_back(temp->val);
            temp=temp->next;
        }
    }
    
    int getRandom() 
    {
        int x=rand()%v1.size();
        return v1[x];
    }
};
