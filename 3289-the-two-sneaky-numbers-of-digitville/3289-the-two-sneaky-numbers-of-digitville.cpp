class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<int>v;
        for(int i=1;i<a.size();i++){
            if(a[i] == a[i-1]) v.push_back(a[i]);
        }
        return v;
    }
};