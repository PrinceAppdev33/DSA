class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int l = 0, odd = 0, even = 0, ans = 0;

        for (int r = 0; r < a.size(); r++) {

            if (a[r] % 2) {
                odd++;
                even = 0;
            }

            while (odd > k) {
                if (a[l] % 2)
                    odd--;
                l++;
            }

            if (odd == k) {
                while (a[l] % 2 == 0) {
                    even++;
                    l++;
                }

                ans += even + 1;
            }
        }

        return ans;
    }
};