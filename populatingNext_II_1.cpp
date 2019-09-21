/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* find_next(Node *root) {
        // walk the root level's next chain until the end or we find such a node that has at least one child
        while (root && !root->left && !root->right) {
            root = root->next;
        }
        if (root) return root->left ? root->left : root->right;
        else return NULL;
    }

 Node* connect(Node *root) {
        if (!root) return NULL;
        if (root->left) {
            if (root->right) root->left->next = root->right;    // if root has right, then that will be left's next
            else root->left->next = find_next(root->next);      // else, walk the root level's next chain
        }
        if (root->right) root->right->next = find_next(root->next); // walk the root level's next chain
        // note that we need to recurse on right first
        if (root->right) connect(root->right);
        if (root->left) connect(root->left);
     return root;
    }

};
