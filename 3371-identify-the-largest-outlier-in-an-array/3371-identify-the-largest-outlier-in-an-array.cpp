class Solution {
public:
    int getLargestOutlier(vector<int>& a) {
        sort(a.begin(),a.end());
        map<int,int>mpp;
        int sum=0;
        for(int x : a) sum += x;
        for(int x : a){
            mpp[x]++;
        }
        int ans=-1e9;
        for(int x : a){
            if((sum-x)%2==0 && mpp.find((sum-x)/2) != mpp.end() && ((sum-x)/2 != x || mpp[x] > 1)){
                ans = max(ans,x);
            }
        }
        return ans;
    }
};