class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int i = node.first;
            int j = node.second;
            for (int k = 0; k < 4; k++) {
                int negr = i + dr[k];
                int negc = j + dc[k];
                if (negr >= 0 && negr < n &&
                    negc >= 0 && negc < m &&
                    ans[negr][negc] == -1) {
                    ans[negr][negc] = ans[i][j] + 1;
                    q.push({negr, negc});
                }
            }
        }

        return ans;
    }
};