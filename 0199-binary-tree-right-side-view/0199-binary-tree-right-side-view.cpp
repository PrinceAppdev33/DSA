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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mpp;
        if(!root) return {};
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int y = p.second;
            if(mpp.find(y) == mpp.end()){
                mpp[y] = node->val;
            }
            if(node->right){
                q.push({node->right, y+1});
            }
            if(node->left){
                q.push({node->left, y+1});
            }
        }
        vector<int>ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};