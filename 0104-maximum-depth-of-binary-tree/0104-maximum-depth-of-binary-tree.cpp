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
    int ans(TreeNode* root, int cnt){
        if(root == nullptr) return cnt;
        int lft=0,rgt=0;
        lft = ans(root->left, cnt+1);
        rgt = ans(root->right,cnt+1);
        return max(lft,rgt);
    }
    int maxDepth(TreeNode* root) {
        return ans(root,0);
    }
};