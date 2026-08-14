class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mpp;
        int ans=0,l=0;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            while(mpp[s[i]] > 1){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};