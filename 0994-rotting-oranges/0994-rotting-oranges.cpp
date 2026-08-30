class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 2)
                    q.push({{i, j}, 0});
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        int ans = 0;
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            ans = max(ans, time);
            q.pop();
            for (int k = 0; k < 4; k++) {
                int negr = i + dr[k];
                int negc = j + dc[k];
                if (negr >= 0 && negr < n && negc >= 0 && negc < m &&
                    arr[negr][negc] == 1) {
                    arr[negr][negc] = 2;
                    q.push({{negr, negc}, time + 1});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};