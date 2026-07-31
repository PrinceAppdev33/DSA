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
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        stack<TreeNode*>s1,s2;
        s1.push(p);
        s2.push(q);
        while(!s1.empty() && !s2.empty()){
            TreeNode* n1 = s1.top();
            TreeNode* n2 = s2.top();
            if(n1->val != n2->val) return false;
            s1.pop();
            s2.pop();
            if ((n1->left == nullptr) != (n2->left == nullptr))

                return false;

            if ((n1->right == nullptr) != (n2->right == nullptr))

                return false;
            if(n1->right) s1.push(n1->right);
            if(n2->right) s2.push(n2->right);
            if(n1->left) s1.push(n1->left);
            if(n2->left) s2.push(n2->left);
        }
        return (s1 == s2);
    }
};