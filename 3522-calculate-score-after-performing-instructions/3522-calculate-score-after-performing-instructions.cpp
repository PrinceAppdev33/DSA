class Solution {
public:
    long long calculateScore(vector<string>& a, vector<int>& v) {
        int n = a.size();
        vector<bool>p(n,false);
        long long score=0, i=0;
        while(i<n && i>=0){
            if(p[i]) break;
            if(a[i] == "add"){
                score += v[i];
                p[i] = true;
                i++;
            } else{
                p[i] = true;
                i = i + v[i];
            }
        }
        return score;
    }
};