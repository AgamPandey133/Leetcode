class Solution {
public:
    int start = 0, maxLen = 0;

    void expand(string &s, int l, int r) {
        int n = s.size();

        while(l >= 0 && r < n && s[l] == s[r]) {
            int len = r - l + 1;

            if(len > maxLen) {
                maxLen = len;
                start = l;
            }

            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++) {
            expand(s, i, i);     
            expand(s, i, i + 1); 
        }

        return s.substr(start, maxLen);
    }
};