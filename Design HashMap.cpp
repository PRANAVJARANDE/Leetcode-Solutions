class MyHashMap {
public:

    class Node {
    public:
        int key;
        int val;
        Node* left;
        Node* right;

        Node(int k, int v) : key(k), val(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* searchNode(Node* root, int k) {
        if (root == nullptr)
            return nullptr;

        if (k == root->key) {
            return root;
        } else if (k < root->key) {
            return searchNode(root->left, k);
        } else {
            return searchNode(root->right, k);
        }
    }

    Node* inOrderSuccessor(Node* root) {
        while (root != nullptr && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int k) {
        if (root == nullptr)
            return nullptr;

        if (k == root->key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* successor = inOrderSuccessor(root->right);
                root->key = successor->key;
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->key);
            }
        } else if (k < root->key) {
            root->left = deleteNode(root->left, k);
        } else {
            root->right = deleteNode(root->right, k);
        }
        return root;
    }

    Node* insertNode(Node* root, Node* newNode) {
        if (!root)
            return newNode;

        if (root->key == newNode->key) {
            root->val = newNode->val;
        } else if (root->key < newNode->key) {
            root->right = insertNode(root->right, newNode);
        } else {
            root->left = insertNode(root->left, newNode);
        }
        return root;
    }

    MyHashMap() : root(nullptr) {}

    void put(int k, int v) {
        Node* newNode = new Node(k, v);
        root = insertNode(root, newNode);
    }

    int get(int k) {
        Node* result = searchNode(root, k);
        if (result == nullptr) {
            return -1;
        }
        return result->val;
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    
};
