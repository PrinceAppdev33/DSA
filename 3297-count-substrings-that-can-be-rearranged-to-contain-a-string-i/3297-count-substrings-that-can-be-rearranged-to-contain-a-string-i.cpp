class Solution {
public:
    long long validSubstringCount(string a, string b) {
        map<char,int>mpp;
        for(char x : b) mpp[x]++;
        int cnt = b.size();
        long long left=0,ans=0;
        for(int i=0;i<a.size();i++){
            if(mpp.find(a[i])!=mpp.end()){
                if(mpp[a[i]] > 0){
                    cnt--;
                }
                mpp[a[i]]--;
            }
            while(cnt == 0){
                ans += a.size() - i;
                if(mpp.find(a[left]) != mpp.end()){
                    mpp[a[left]]++;
                    if(mpp[a[left]] > 0) cnt++;
                }
                left++;
            }
        }
        return ans;

    }
};