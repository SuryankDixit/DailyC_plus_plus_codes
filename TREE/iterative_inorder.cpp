// 94. Binary Tree Inorder Traversal ITERATIVE
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
        vector<int> v;
        if(root==NULL)
            return v;
        stack<TreeNode*> s;
        while(root!=NULL || !s.empty())
        {
            while(root!=NULL)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            v.push_back(root->val);
            root=root->right;
        }
        return v;
    }
};
