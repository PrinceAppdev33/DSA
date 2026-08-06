class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());

        int n = pizzas.size();
        int days = n / 4;
        int odd = (days + 1) / 2;
        int even = days / 2;

        int l = 0, r = n - 1;
        long long ans = 0;

        while (odd--) {
            ans += pizzas[r];
            r--;
            l += 3;
        }

        while (even--) {
            ans += pizzas[r - 1];
            r -= 2;
            l += 2;
        }

        return ans;
    }
};