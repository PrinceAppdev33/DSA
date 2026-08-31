/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        ListNode* cur = head;
        while(cur){
            v.push_back(cur->val);
            cur = cur->next;
        }
        int mini=1e9,mx=-1e9,p=-1,z=0,q=-1;
        for(int i=1;i<v.size()-1;i++){
            if((v[i] > v[i-1] && v[i] > v[i+1]) || (v[i] < v[i-1] && v[i] < v[i+1])){
                if(z==0){
                    p = i;
                    q=i;
                    z++;
                } else{
                    mini = min(mini,abs(i-p));
                    mx = max(mx,abs(i-q));
                    p = max(p,i);
                    q=min(q,i);
                    z++;
                }
            }
        }
        if(p==-1 || z<2) return {-1,-1};
        return {mini,mx};
    }
};