class Solution {
public:
    void fillLPSArray(vector<int> &v, vector<int>&lps) {
        int n = v.size();

        int i = 0, j = 1;
        while (j < n) {
            if (v[i] == v[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if (i == 0)
                    lps[j++] = 0;
                else
                    i = lps[i - 1];
            }
        }
    }

    int findInNums(vector<int>& nums ,vector<int>& pat, vector<int>&lps, int ind){
        int n = nums.size();
        int m = pat.size();

        int i = ind, j = 0;
        while(i < n && j < m){
            if(nums[i] == pat[j]){
                i++; j++;
                if(j == m) return i;
            }else{
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }

        return -1;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int m = groups.size();

        int i = 0, j = 0;
        while(j < m && i < n) {
            vector<int> lps(groups[j].size(), 0);
            fillLPSArray(groups[j], lps);
            i = findInNums(nums, groups[j], lps, i);
            if(i == -1) return 0;
            j++;
        }

        return j == m;
    }
};