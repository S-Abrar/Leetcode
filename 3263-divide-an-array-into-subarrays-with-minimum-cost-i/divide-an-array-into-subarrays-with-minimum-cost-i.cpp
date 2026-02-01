class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        long long first = nums[0];
        long long minSecond = LLONG_MAX;
        long long ans = LLONG_MAX;

        for (int i = 1; i < n; i++) {
            if (minSecond != LLONG_MAX) {
                ans = min(ans, first + minSecond + nums[i]);
            }
            minSecond = min(minSecond, (long long)nums[i]);
        }

        return (int)ans;
    }
};
