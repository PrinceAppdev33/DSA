class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        int n = a.size();
        vector<int>ans(n,0);
        map<int,vector<int>>mpp;
        for(int i=0;i <n; i++) mpp[a[i]].push_back(i);
        sort(a.begin(),a.end());
        int z=0;
        for(auto it : mpp){
            vector<int>v = it.second;
            for(int x : v){
                ans[x] = z;
            }
            z += v.size();
        }
        return ans;
    }
};