class MyLinkedList {
public:
class Node 
{
public:
    int val;
    node* next;
    node(int x) 
    {
        val(x);
        next(NULL); 
    }
};

    node* head;

    MyLinkedList() 
    {
        head = NULL;
    }

        int get(int index) 
        {
        node* curr = head;
        int count = 0;

        while (curr!=NULL && count < index) 
        {
            curr = curr->next;
            count++;
        }

        if (curr!=NULL)
            return curr->val;

        return -1;
    }

    void addAtHead(int val) 
    {
        node* newNode = new node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) 
    {
        node* newNode = new node(val);

        if (!head) {
            head = newNode;
            return;
        }

        node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }

        node* newNode = new node(val);
        node* curr = head;
        int count = 0;

        while (curr && count < index - 1) {
            curr = curr->next;
            count++;
        }

        if (curr) {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || !head)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* curr = head;
        int count = 0;

        while (curr && count < index - 1) {
            curr = curr->next;
            count++;
        }

        if (curr && curr->next) {
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
};
