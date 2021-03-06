// 988. Smallest String Starting From Leaf
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
    string smallestFromLeaf(TreeNode* root) {
       string ans;
        util(root, ans, "");
        return ans;
    }
    void util(TreeNode* root,string &ans,string temp)
    {
       if(!root) return;
        if(!root->left && !root->right) {
            temp = string(1,'a' + root->val)+temp;
            //reverse(temp.begin(), temp.end());
            if(!ans.size()) {ans = temp; cout<<ans<<endl;}
             else ans = min(ans, temp);
            return;
        }
        temp = string(1,'a' + root->val)+temp;
        util(root->left, ans, temp);
        util(root->right, ans, temp);
    }
};
