/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result = -1e9;

    int ans(TreeNode* root){
        if(root == nullptr) return 0;

        int left = max(0,ans(root->left));
        int right = max(0,ans(root->right));
        result = max(result, left + right + root->val);
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        ans(root);
        return result;
    }
};