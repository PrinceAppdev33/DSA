class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n = a.size();
        if(n==1) return 0;
        int b[n];
        int mini = 1e9;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,a[i]);
            b[i] = mini;
        }
        int mx = -1e9;
        for(int i=0;i<n;i++){
            mx = max(mx,a[i]);
            if(mx-b[i] <= k) return i;
        }
        return -1;
    }
};