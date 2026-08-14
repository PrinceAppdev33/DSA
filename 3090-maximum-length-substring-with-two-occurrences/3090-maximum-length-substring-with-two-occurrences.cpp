class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,n=s.size(),ans=0;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            while(mpp[s[i]] > 2){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};