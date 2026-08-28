class Solution {
public:
    long long countBadPairs(vector<int>& a) {
        map<int,int>mpp;
        long long sum=0, n = a.size();
        for(int i=0;i<a.size();i++){
            int key = a[i]-i;
            sum += mpp[key];
            mpp[key]++;
        }
        return n*(n-1)/2 - sum;
    }
};