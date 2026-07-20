class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dir[8][2] = {
            {-1, -2},
            {-2, -1},
            {-1, 2},
            {-2, 1},
            {1, -2},
            {2, -1},
            {1, 2},
            {2, 1}
        };
        queue<pair<int, int>> q; 
        q.push({start[0], start[1]}); 
        int vis[8][8] = {0}; 
        int ans = 0; 
        vis[start[0]][start[1]] = 1; 
        while(q.size() > 0) {
            int sz = q.size(); 
            while(sz-- > 0) {
                pair<int, int> pr = q.front(); 
                q.pop(); 
                if(pr.first == target[0] && pr.second == target[1]) {
                    if(ans % 2 == 0) return true; 
                }
                for(auto it: dir) {
                    int nx = it[0] + pr.first, ny = it[1] + pr.second; 
                    if(nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
                        // valid 
                        if(!vis[nx][ny]) {
                            q.push({nx, ny}); 
                            vis[nx][ny] = 1; 
                        }
                    }
                }
            }
            ans++; 
        }
        return false; 
    }
};
