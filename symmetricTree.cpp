/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v = {}; 
    vector<int> m = {}; 
    
    void rightTree(TreeNode* root, vector<int>& v){
        if (!root){
            v.push_back(-1); 
            return;
        }

        v.push_back(root->val);
        rightTree(root->right, v);
        rightTree(root->left, v);
    }


    void leftTree(TreeNode* root, vector<int>&m){
        if (!root){
            m.push_back(-1); 
            return;
        }

        m.push_back(root->val);
        leftTree(root->left, m);
        leftTree(root->right, m);
    }
    
    bool isSymmetric(TreeNode* root) {
        rightTree(root, v); 
        leftTree(root,m); 
        if (m==v) return true; 
        else return false; 
    }
};


//CHECK ON YOUR PC
/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v = {};
vector<int> m = {};

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void rightTree(TreeNode* root, vector<int>& v){
        if (!root){
            v.push_back(-1);
            return;
        }

        v.push_back(root->val);
        rightTree(root->right, v);
        rightTree(root->left, v);
    }


    void leftTree(TreeNode* root, vector<int>&m){
        if (!root){
            m.push_back(-1);
            return;
        }

        m.push_back(root->val);
        leftTree(root->left, m);
        leftTree(root->right, m);
    }
    bool isSymmetric(TreeNode* root) {
        rightTree(root, v);
        leftTree(root,m);

        if (m==v) return true;
        else return false;
    }
};

int main(){
    TreeNode um(1),dois(2),tres(3), quatro(4),cinco(2),seis(4), sete(3);
    (&um)->left = &dois;
    (&um)->right = &cinco;
    (&dois)->left = &tres;
    (&dois)->right = &quatro;
    (&cinco)->left = &seis;
    (&cinco)->right = &sete;

    Solution k;
    k.rightTree(&um, v);
    k.leftTree(&um,m);

    if (m==v) cout<<"true" << endl;
    else cout << "false" << endl;





}
*/
