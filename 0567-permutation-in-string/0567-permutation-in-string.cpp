class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1,mp2;
        for(char c : s1) mp1[c]++;
        int x = s1.size(),n=s2.size(),l=0,z=0;
        for(int i=0;i<n;i++){
            mp2[s2[i]]++;
            z++;
            if(z > x){
                mp2[s2[l]]--;
                if(mp2[s2[l]]==0) mp2.erase(s2[l]);
                l++;
                z--;
            }
            if(mp1 == mp2) return true;
        }
        return false;
    }
};