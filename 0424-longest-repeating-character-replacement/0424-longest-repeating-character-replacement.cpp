class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mpp;
        int l=0,ans=0,n=s.size(),mx=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            mx = max(mx,mpp[s[i]]);
            if((i-l+1) - mx > k){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};