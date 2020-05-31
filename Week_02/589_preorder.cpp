/*
589. N叉树的前序遍历
给定一个 N 叉树，返回其节点值的前序遍历。*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        Traversl(root,&result);
        return result;
    }
    void Traversl(Node* root,vector<int>* result)
    {
        if(root!=NULL)
        {
            result->push_back(root->val);
           int legth=root->children.size();
           for(int i=0;i<legth;++i)
           {
              Traversl(root->children[i],result);
           }
        }
    }
};
