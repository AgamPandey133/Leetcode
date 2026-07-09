class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pat) {
        int n = nums.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        int pre = 0, suff = 1;

        while (suff < m) {
            if (pat[pre] == pat[suff]) {
                lps[suff] = pre + 1;
                pre++;
                suff++;
            } else {
                if (pre == 0) {
                    lps[suff] = 0;
                    suff++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }

        vector<int> arr;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                arr.push_back(1);
            else if (nums[i] == nums[i - 1])
                arr.push_back(0);
            else
                arr.push_back(-1);
        }

        int ans = 0;
        int i = 0, j = 0;

        while (i < arr.size()) {
            if (arr[i] == pat[j]) {
                i++;
                j++;

                if (j == m) {
                    ans++;
                    j = lps[j - 1]; 
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }

        return ans;
    }
};