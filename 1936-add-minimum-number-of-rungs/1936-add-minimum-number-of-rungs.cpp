class Solution {
public:
    int addRungs(vector<int>& a, int d) {
        int ans=0;
        ans += (a[0]-1)/d;
        for(int i=0;i<a.size()-1;i++){
            ans += (a[i+1]-a[i]-1)/(d);
        }
        return ans;
    }
};