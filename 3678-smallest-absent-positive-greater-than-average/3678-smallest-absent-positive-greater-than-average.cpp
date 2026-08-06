class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double avg = accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
        int count = 1;

        while (true) {
            if (count > avg &&
                find(nums.begin(), nums.end(), count) == nums.end()) {
                return count;
            }
            count++;
        }
    }
};