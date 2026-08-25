class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char, long long> mpp;
        long long sum = 0, mx = 0;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]] += cost[i];
            sum += cost[i];
        }

        for (auto it : mpp) {
            mx = max(mx, it.second);
        }

        return sum - mx;
    }
};