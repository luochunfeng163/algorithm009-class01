/*
144. 二叉树的前序遍历
给定一个二叉树，返回它的 前序 遍历。*/
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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> result;
      Traversal(root,&result);
      return result;
    }
    void Traversal(TreeNode* root,vector<int>* result)
    {
        if(root!=NULL)
        {
            result->push_back(root->val);
            if(root->left!=NULL)
            {
                Traversal(root->left,result);
            }
            if(root->right!=NULL)
            {
                Traversal(root->right,result);
            }

        }
    }
};
