class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int ans=0,l=0,n=a.size(),zr=0;
        for(int i=0l;i<n;i++){
            if(a[i]==0) zr++;
            while(zr > k){
                if(a[l] == 0) zr--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};