class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int l = k, r = k;

        int mini = INT_MAX;
        long long value;
        int ans = INT_MIN;
        while (l > 0 || r < n - 1) {
            if (l == 0)
                r++;
            else if (r == n - 1)
                l--;
            else if (nums[l - 1] < nums[r + 1])
                r++;
            else
                l--;

            mini = min(mini, min(nums[l], nums[r]));
            ans = max(ans, mini * (r - l + 1));
        }
        while (l >= 0) {
            mini = min({mini, nums[l], nums[r]});
            value = mini * (r - l + 1);

            ans = max(ans, (int)value);
            l--;
        }
        while (l >= 0 && r < n) {
            mini = min({mini, nums[l], nums[r]});
            value = mini * (r - l + 1);

            ans = max(ans, (int)value);
            r++;
        }

        return ans;
    }
};