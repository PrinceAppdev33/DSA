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
 class helper{
    public:
        int mini, maxi, maxsize;
        helper(int mini, int maxi, int maxsize){
            this->mini = mini;
            this->maxi = maxi;
            this->maxsize = maxsize;
        }
 };
class Solution {
public:
    int ans = 0;
    helper subtree(TreeNode* root){
        if(!root) return helper(INT_MAX,INT_MIN,0);

        auto left = subtree(root->left);
        auto right = subtree(root->right);

        if(left.maxi < root->val && root->val < right.mini){
            int cursum = left.maxsize + right.maxsize + root->val;
            ans = max(ans, cursum);
            return helper(min(left.mini,root->val),max(right.maxi,root->val),left.maxsize + right.maxsize + root->val);
        }
        return helper(INT_MIN, INT_MAX,max(left.maxsize,right.maxsize));
    }
    int maxSumBST(TreeNode* root) {
        max(0,subtree(root).maxsize);
        return ans;
    }
};