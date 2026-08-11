class Solution {
public:
    int maxNonOverlapping(vector<int>& a, int t) {
        map<int,int>mpp;
        mpp[0] = 1;
        int n = a.size(), ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum += a[i];
            int d = sum - t;
            if(mpp.find(d)!=mpp.end()){
                ans++;
                mpp.clear();
                mpp[0] = 1;
                sum = 0;
            } else{
                mpp[sum]++;
            }
        }
        return ans;
    }
};