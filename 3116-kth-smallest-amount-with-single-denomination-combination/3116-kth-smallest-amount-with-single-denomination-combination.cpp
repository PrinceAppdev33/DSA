class Solution {
private:
    vector<int> coins;
    long long k;

public:
    long long findKthSmallest(vector<int>& coins, long long k) {
        this->coins = coins;
        this->k = k;

        long long l = 1, r = 1e11;

        while (l < r) {
            long long mid = (l + r) >> 1;

            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool check(long long mx) {
        long long cnt = 0;
        int n = coins.size();

        for (int i = 1; i < (1 << n); ++i) {
            long long v = 1;

            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1) == 1) {
                    v = lcm(v, (long long)coins[j]);

                    if (v > mx)
                        break;
                }
            }

            int m = __builtin_popcount(i);

            if (m % 2 == 1) {
                cnt += mx / v;
            } else {
                cnt -= mx / v;
            }
        }

        return cnt >= k;
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};