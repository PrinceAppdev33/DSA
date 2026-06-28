class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=1;i<a[0];i++){
            if(a[0]!=i){
                a[0] = i;
                break;
            }
        }
        int n = a.size();
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1] > 1) a[i] = a[i-1]+1;
        }
        return a[n-1];
    }
};