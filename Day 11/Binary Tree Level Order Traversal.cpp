class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>>v;
         if(!root)
         return {};

         q.push(root);
         

         while(!q.empty()){
             vector<int>a;
             int size=q.size();

             while(size--){
                 TreeNode* curr=q.front();
                 q.pop();

                 a.push_back(curr->val);
                 if(curr->left)
                 q.push(curr->left);

                 if(curr->right)
                 q.push(curr->right);
             }
             v.push_back(a);

         }
         return v;
    }
};