class Solution {
public:
    vector<int> fillLPSArray(string s) {
        int n = s.size();
        if (n == 1)
            return {0};
        vector<int> lps(n);
        lps[0] = 0;
        lps[1] = 0;

        // if(s[0] == s[1]) lps[1] = 1;
        int i = 0, j = 1;

        while (j < n) {
            if (s[i] == s[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            } else {
                if (i == 0) {
                    lps[j] = 0;
                    j++;
                } else {
                    i = lps[i - 1];
                }
            }
        }

        return lps;
    }
    int strStr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (m > n)
            return -1;
        if (m == 0)
            return 0;
        if (m == n)
            return s1 == s2 ? 0 : -1;

        vector<int> lps = fillLPSArray(s2);

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }

        if (j == s2.size())
            return i - j;

        return -1;
    }
};