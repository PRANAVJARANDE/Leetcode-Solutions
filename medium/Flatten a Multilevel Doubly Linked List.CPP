/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
   
    Node* flatten(Node* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        Node* n1 = flatten(head->next);
        Node* flatchild = flatten(head->child);

        // Linking
        if (flatchild != NULL) 
        {
            head->next = flatchild;
            flatchild->prev = head;
            while (flatchild->next != nullptr) 
            {
                flatchild = flatchild->next;
            }
            flatchild->next = n1;
            if (n1 != NULL) 
            {
                n1->prev = flatchild;
            }
            head->child = NULL;
        }

        return head;
    }
};
