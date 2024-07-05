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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=INT_MAX,maxi=INT_MIN;
        ListNode *prev=NULL;
        int fo=-1;
        int pc=-1;
        int cnt=0;
        while(head!=NULL)
        {
            if(prev!=NULL && head->next!=NULL){
                int a1=prev->val;
                int a2=head->val;
                int a3=head->next->val;
                
                if((a1<a2 && a2>a3) || (a1>a2 && a2<a3)){
                    if(fo==-1){
                        fo=cnt;
                        pc=cnt;
                    }
                    else{
                        mini=min(mini,cnt-pc);
                        maxi=max(maxi,cnt-fo);
                        pc=cnt;
                    }
                }
            }
            prev=head;
            head=head->next;
            cnt++;
        }
        if(mini==INT_MAX){
            return {-1,-1};
        }
        return {mini,maxi};
    }
};
