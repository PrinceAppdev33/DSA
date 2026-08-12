class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int l=0,ans=0;
        map<int,int>mpp;
        for(int r=0;r<a.size();r++){
            mpp[a[r]]++;
            while(mpp[a[r]] > k){
                mpp[a[l]]--;
                l++;
            }
            ans= max(ans,r-l+1);
        }
        return ans;
    }
};