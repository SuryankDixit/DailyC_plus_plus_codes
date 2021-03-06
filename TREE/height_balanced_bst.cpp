// 110.Height Balanced Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // TRAVERSING THE WHOLE TREE ONLY ONE TIME 
 // COMPLEXITY: O(N)
 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool status=true;
        is_balanced(root,status);
        return status;
    }
    int is_balanced(TreeNode* root,bool &status)
    {
        if(root==NULL)
            return 0;
        
        int l=is_balanced(root->left,status);
        int r=is_balanced(root->right,status);
        if(abs(l-r)>1)
            status=false;
        return 1+max(l,r);
    }
};
