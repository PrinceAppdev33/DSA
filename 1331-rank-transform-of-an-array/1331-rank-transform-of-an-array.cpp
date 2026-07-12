class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        map<int,vector<int>>mpp;
        for(int i=0;i<a.size();i++){
            mpp[a[i]].push_back(i);
        }
        int z=1;
        vector<int>ans(a.size(),0);
        for(auto it : mpp){
            for(int x : it.second){
                ans[x] = z;
            }
            z++;
        }
        return ans;
    }
};