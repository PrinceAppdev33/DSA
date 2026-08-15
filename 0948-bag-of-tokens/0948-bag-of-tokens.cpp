class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        int i=0,j=a.size()-1,score=0,ans=0;
        sort(a.begin(),a.end());
        while(i <= j){
            if( p >= a[i]){
                p -= a[i];
                i++;
                score++;
                ans = max(ans,score);
            } else if(score > 0){
                p += a[j];
                j--;
                score--;
            } else break;
            
        }
        return ans;
    }
};