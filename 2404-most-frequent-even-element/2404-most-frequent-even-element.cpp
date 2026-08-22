class Solution {
public:
    int mostFrequentEven(vector<int>& a) {
        map<int,int>mpp;
        for(int x : a) mpp[x]++;
        int ans = -1, mini = -1e9;
        for (auto it = mpp.rbegin(); it != mpp.rend(); ++it) {
            if(it->first%2==0){
                if(it->second >= mini){
                    ans = it->first;
                    mini = it->second;
                }
            }
        }
        return ans;
    }
};