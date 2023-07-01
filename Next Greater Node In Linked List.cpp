class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return ans;
    }
};
