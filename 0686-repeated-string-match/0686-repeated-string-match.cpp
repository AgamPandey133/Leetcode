class Solution {
public:
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if (len == 0)
                    i++;
                else
                    len = lps[len - 1];
            }
        }

        return lps;
    }

    bool kmp(string &text, string &pat) {
        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0;

        while (i < text.size()) {
            if (text[i] == pat[j]) {
                i++;
                j++;

                if (j == pat.size())
                    return true;
            } else {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string s = a;
        int cnt = 1;

        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }

        if (kmp(s, b))
            return cnt;

        s += a;

        if (kmp(s, b))
            return cnt + 1;

        return -1;
    }
};