/*
94. 二叉树的中序遍历
给定一个二叉树，返回它的中序 遍历。*/

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
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        inTraversal(root,&result);
        return result;
    }

    void inTraversal(TreeNode* root,vector<int>* result)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left)
        {
            inTraversal(root->left,result);
        }
        result->push_back(root->val);
        if(root->right)
        {
            inTraversal(root->right,result);
        }
    }
};
