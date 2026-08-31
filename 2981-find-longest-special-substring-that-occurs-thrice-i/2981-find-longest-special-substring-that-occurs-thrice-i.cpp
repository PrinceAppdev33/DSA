class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mpp;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = i; j < n; j++) {
                if (s[j] != s[i]) break;

                cnt++;
                mpp[{s[i], cnt}]++;
            }
        }

        int ans = -1;

        for (auto it : mpp) {
            if (it.second >= 3) {
                ans = max(ans, it.first.second);
            }
        }

        return ans;
    }
};