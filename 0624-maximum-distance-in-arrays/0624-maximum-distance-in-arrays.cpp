class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int mini = a[0][0];
        int maxi = a[0].back();
        int ans = 0;

        for (int i = 1; i < a.size(); i++) {
            ans = max(ans, abs(a[i].back() - mini));
            ans = max(ans, abs(maxi - a[i][0]));

            mini = min(mini, a[i][0]);
            maxi = max(maxi, a[i].back());
        }

        return ans;
    }
};