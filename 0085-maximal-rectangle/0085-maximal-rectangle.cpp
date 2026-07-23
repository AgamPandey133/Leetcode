class Solution {
public:
    int largestRectangleArea(vector<int> &h){
        int n = h.size();

        stack<int> st;
        int ans = 0;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || h[st.top()] >= h[i])){
                int height = h[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> v(m);

        for(int j = 0; j < m; j++)
            v[j] = mat[0][j] - '0';

        int ans = largestRectangleArea(v);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == '0')
                    v[j] = 0;
                else
                    v[j]++;
            }

            ans = max(ans, largestRectangleArea(v));
        }

        return ans;
    }
};