class Solution {
public:
    long long minMoves(vector<int>& a) {
        long long sum = 0;
        int idx = -1, n = a.size();

        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] < 0)
                idx = i;
        }

        if (sum < 0) return -1;
        if (idx == -1) return 0;

        long long need = -1LL * a[idx];
        long long ans = 0;

        int left = (idx - 1 + n) % n;
        int right = (idx + 1) % n;

        int leftDist = 1;
        int rightDist = 1;

        while (need > 0) {

            // choose the closer side
            if (leftDist <= rightDist) {

                long long take = min(need, (long long)max(0, a[left]));

                ans += take * leftDist;
                need -= take;

                left = (left - 1 + n) % n;
                leftDist++;

            } else {

                long long take = min(need, (long long)max(0, a[right]));

                ans += take * rightDist;
                need -= take;

                right = (right + 1) % n;
                rightDist++;
            }
        }

        return ans;
    }
};