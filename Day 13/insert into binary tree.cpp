class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root,  int target) {
        if(root==NULL)
        {
            return new TreeNode(target);
        }
        else if (target>root->val)
        {
            root->right=insertIntoBST(root->right,target);
        }
        else 
        {
            root->left=insertIntoBST(root->left,target);
        }
        return root;
    }
};