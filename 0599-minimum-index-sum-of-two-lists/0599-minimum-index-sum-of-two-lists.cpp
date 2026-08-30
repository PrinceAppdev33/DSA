class Solution {
public:
    vector<string> findRestaurant(vector<string>& a, vector<string>& b) {
        map<string,int>mp1,mp2;
        for(int i=0;i<a.size();i++){
            mp1[a[i]] = i;
        }
        for(int i=0;i<b.size();i++){
            mp2[b[i]] = i;
        }
        int ans = 1e9;
        vector<string>v;
        for(int i=0;i<a.size();i++){
            if(mp1.find(a[i]) != mp1.end() && mp2.find(a[i]) != mp2.end()) ans = min(ans,mp1[a[i]] + mp2[a[i]]);
        }
        for(int i=0;i<a.size();i++){
            if(mp1.find(a[i]) != mp1.end() && mp2.find(a[i]) != mp2.end() && mp1[a[i]] + mp2[a[i]] == ans){
                v.push_back(a[i]);
            }
        }
        return v;

    }
};