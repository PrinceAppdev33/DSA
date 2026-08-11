class Solution {
public:
    string reformat(string s) {
        int n = s.size();
        vector<char>v,p;
        for(char c : s){
            if(isdigit(c)) v.push_back(c);
            else p.push_back(c);
        }
        if(min(v.size(),p.size()) < n/2) return "";
        int vp=0,pv=0;
        string ans;
        bool boo = true;
        if(v.size() < p.size()) boo = false;
        else boo = true;
        while(vp < v.size() || pv < p.size()){
            if(boo){
                ans += v[vp];
                vp++;
            } 
            else{
                 ans += p[pv];
                 pv++;
            }
            boo = !boo;
        }
        return ans;
    }
};