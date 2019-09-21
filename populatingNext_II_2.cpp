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
    Node* find(Node* root){
        if (!root) return NULL;
        
        if (root->left) return root->left; 
        if (root->right) return root->right; 
        else return find(root->next); 
     }
    Node* connect(Node* root) {
        
        if (!root) return NULL;
        
        if(root->left){
            if(root->right) root->left->next = root->right;
            else root->left->next = find(root->next); 
            
        }
        if(root->right) root->right->next = find(root->next); 
        
        connect(root->right);
        connect(root->left); 
        return root; 
    }
};
