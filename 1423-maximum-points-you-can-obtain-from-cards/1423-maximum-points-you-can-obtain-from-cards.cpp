class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size(),sum=0;
        for(int x : a) sum += x;
        k = n-k;
        int ans=0,csum=0,l=0;
        for(int i=0;i<n;i++){
            csum += a[i];
            if((i-l+1) > k){
                csum -= a[l];
                l++;
            }
            if((i-l+1) == k) ans = max(ans,sum-csum);
            
        }
        return ans;
        
    }
};