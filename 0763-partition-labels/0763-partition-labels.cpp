class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>lst;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(!lst.count(s[i])) lst[s[i]] = i;
        }
        int i=0;
        vector<int>v;
        int ans = 0,start=0;
        while(i<n){
            char c = s[i];
            int j = lst[c];
            ans = max(ans,j);
            if(i==ans){
                v.push_back(ans-start+1);
                start = i+1;
            }
            i++;
        } 
        return v;
    }
};