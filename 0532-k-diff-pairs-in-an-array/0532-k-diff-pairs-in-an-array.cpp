class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        map<int, int> mpp;

        for (int x : a) {
            mpp[x]++;
        }

        int ans = 0;

        if (k == 0) {
            for (auto it : mpp) {
                if (it.second >= 2) {
                    ans++;
                }
            }
        } else {
            for (auto it : mpp) {
                int x = it.first;

                if (mpp.find(x + k) != mpp.end()) {
                    ans++;
                }
            }
        }

        return ans;
    }
};