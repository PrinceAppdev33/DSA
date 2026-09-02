class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int i=0;
        vector<vector<int>>ans;
        int n = a.size();
        while(i<n){
            vector<int>v;
            if(abs(a[i]-a[i+2]) > k) return {};
            v.push_back(a[i]);
            v.push_back(a[i+1]);
            v.push_back(a[i+2]);
            ans.push_back(v);
            i += 3;
        }
        return ans;
    }
};