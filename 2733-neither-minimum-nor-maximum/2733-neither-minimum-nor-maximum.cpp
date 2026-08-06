class Solution {
public:
    int findNonMinOrMax(vector<int>& a) {
        sort(a.begin(),a.end());
        int n = a.size();
        if(n <= 2) return -1;
        return a[1];
    }
};