class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<int>ans;
        map<int,int>mpp;
        int n = a.size();
        for(int i =0;i<n;i++){
            mpp[i] = abs(x-a[i]);
        }
        vector<pair<int, int>> v;
        for (auto &it : mpp) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        k--;
        for(auto &it : v){
            ans.push_back(a[it.second]);
            if(k==0) break;
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};