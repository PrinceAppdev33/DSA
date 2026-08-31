class Solution {
public:
    int maxSatisfied(vector<int>& a, vector<int>& b, int m) {
        int n = a.size(), l=0,sum=0;
        map<int,int>mpp;
        int x = m;
        for(int i=0;i< n;i++){
            if(b[i]==1) sum += a[i];
            m--;
            if(m<0){
                if(b[l]==1) sum -= a[l];
                l++;
                m++;
            }
            if(m==0) mpp[sum] = l;
        }
        auto it = mpp.rbegin();
        int p = it->second;
        int q = p + x-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i < p || i>q){
                if(b[i] == 0) ans+= a[i];
            } else{
                ans += a[i];
            }
        }
        return ans;
    }
};