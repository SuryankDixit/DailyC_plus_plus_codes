//105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=inorder.size();
        return buildtreehelper(preorder,inorder,0,len-1,0,len-1);
    }

    TreeNode* buildtreehelper(vector<int>& preorder, vector<int>& inorder,int inS,int inE,int preS,int preE)
    {
        if(inS>inE)
            return NULL;
        
        int rootdata=preorder[preS];
        int root_index=-1;
        for(int i=inS;i<=inE;i++)
        {
            if(rootdata==inorder[i]){
                root_index=i;
                break;
            }
        }
        int LinS = inS;
        int LinE = root_index-1;
        int LpreS = preS+1;
        int LpreE = LinE-LinS+LpreS;
        int RinS = root_index+1;
        int RinE = inE;
        int RpreS = LpreE+1;
        int RpreE = preE;
        
        TreeNode* root=new TreeNode(rootdata);
        root->left= buildtreehelper(preorder,inorder,LinS,LinE,LpreS,LpreE);
        root->right= buildtreehelper(preorder,inorder,RinS,RinE,RpreS,RpreE);
        
        return root;
    }
};
