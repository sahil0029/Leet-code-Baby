class Solution {
public:
    bool findTarget(TreeNode* root, int k);

    void fillVectorInorderTraversal(TreeNode* node, vector<short>&v);
};
bool Solution::findTarget(TreeNode* root, int k) {
    vector<short> v;
    short leftPtr=0, rightPtr, sum;
    if (root != nullptr) {
        fillVectorInorderTraversal(root, v);
    }
    rightPtr = v.size()-1;
    while(leftPtr < rightPtr) {
        sum = v[leftPtr]+v[rightPtr];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            ++leftPtr;
        } else {
            --rightPtr;
        }
    }
    return false;
}

void Solution::fillVectorInorderTraversal(TreeNode* node, vector<short>&v) {
    if (node->left != nullptr) {
        fillVectorInorderTraversal(node->left, v);
    }
    v.push_back(node->val);
    if (node->right != nullptr) {
        fillVectorInorderTraversal(node->right, v);
    }
    return;
}