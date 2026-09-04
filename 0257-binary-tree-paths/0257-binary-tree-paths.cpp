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
    void dfs(vector<string>&ans, TreeNode* root, string cur){
        if(!root) return;
        cur += to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(cur);
            return;
        } 
        cur += "->";
        dfs(ans,root->left,cur);
        dfs(ans,root->right,cur);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string cur;
        dfs(ans,root,cur);
        return ans;
    }
};