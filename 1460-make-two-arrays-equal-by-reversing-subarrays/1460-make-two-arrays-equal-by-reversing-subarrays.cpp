class Solution {
public:
    bool canBeEqual(vector<int>& a, vector<int>& b) {
        map<int,int>mp1,mp2;
        for(int x : a) mp1[x]++;
        for(int x : b) mp2[x]++;
        return (mp1 == mp2);
    }
};