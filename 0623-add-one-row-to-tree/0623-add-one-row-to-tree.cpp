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
    void solve(TreeNode* root, int val, int d, int  cnt){
        if(!root) return ;
        if(cnt == d){
            TreeNode* lft = root->left;
            TreeNode* rgt = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = lft;
            root->right->right = rgt;
        }
        solve(root->left,val,d,cnt + 1);
        solve(root->right,val,d,cnt + 1);
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            node->right = NULL;
            return node;
        }
        solve(root,val,depth-1,1);
        return root;
    }
};