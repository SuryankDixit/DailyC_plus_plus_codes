
// 124. Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;
        max_path_sum(root,max_sum);
        return max_sum;
    }
    
    int max_path_sum(TreeNode* root,int &max_sum)
    {
        if(root==NULL)
            return 0;
        
        int l=max_path_sum(root->left,max_sum);
        int r=max_path_sum(root->right,max_sum);
        int Max=max(root->val,root->val+max(l,r));
        int Max_l_r= root->val+l+r;
        max_sum=max(max_sum,max(Max,Max_l_r));
        cout<<max_sum<<endl;
        return max(root->val,root->val+max(l,r));
    }
};
