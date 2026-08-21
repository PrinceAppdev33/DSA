class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sum1=0,sum2=0;
        for(int x : a) sum1 += x;
        for(int x : b) sum2 += x;
        int df = (sum2 - sum1)/2;
        unordered_set<int> setB(b.begin(), b.end());
        for(int x : a){
            if(setB.count(x + df)){
                return {x,x+df};
            }
        }
        return {};
    }
};