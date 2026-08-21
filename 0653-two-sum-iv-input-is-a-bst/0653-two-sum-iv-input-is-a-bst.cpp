class BSTiterator {
    stack<TreeNode*>st;
    bool reverse = true;
    // true -> before
    // false -> next
    public : 
        BSTiterator(TreeNode* root, bool isreverse){
            reverse = isreverse;
            pushall(root);
        }
        int next(){
            TreeNode * node = st.top();
            st.pop();
            if(!reverse) pushall(node->right);
            else pushall(node->left);
            return node->val;
        }
        bool hasnext(){
            return !st.empty();
        }

    private : 
        void pushall(TreeNode* root){
            while(root){
                st.push(root);
                if(reverse) root = root->right;
                else root = root->left;
            }
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator l(root, false);
        BSTiterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};