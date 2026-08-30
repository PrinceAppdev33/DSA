class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        map<string,vector<int>>mpp;
        for(int i=0;i<a.size();i++){
            string dum = a[i];
            sort(dum.begin(),dum.end());
            mpp[dum].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it : mpp){
            vector<string>res;
            auto p = it.second;
            for(int x : p){
                res.push_back(a[x]);
            }
            ans.push_back(res);
        }
        return ans;

    }
};