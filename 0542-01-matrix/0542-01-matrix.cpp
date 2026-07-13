class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto &d : dir){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }

        return dist;
    }
};
