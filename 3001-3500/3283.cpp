#define pii pair<int, int>
#define F first
#define S second

int moves[50][50][50][50];
int dp[2][16][1 << 16];

vector<pii> knight_diff = {
    {-2, 1}, {-2, -1}, {2, 1}, {2, -1}, 
    {-1, 2}, {-1, -2}, {1, 2}, {1, -2}
};

bool already_computed = false;

class Solution {
    
    void Expand (int x, int y) {
        vector<vector<bool>> visited(50, vector<bool>(50, false));
        queue<pii> q;
        
        moves[x][y][x][y] = 0;
        q.push({x, y});
        visited[x][y] = true;
        
        while (!q.empty()) {
            pii s = q.front();
            q.pop();
            
            for (auto i : knight_diff) {
                int nxt_x = i.F + s.F;
                int nxt_y = i.S + s.S;
                
                bool is_valid = (nxt_x >= 0 && nxt_x < 50) && (nxt_y >= 0 && nxt_y < 50);
                if (!is_valid || visited[nxt_x][nxt_y]) continue;
                
                moves[x][y][nxt_x][nxt_y] = 1 + moves[x][y][s.F][s.S];
                q.push({nxt_x, nxt_y});
                visited[nxt_x][nxt_y] = true;
            }
        }
    }
    
    void CalculateAll () {
        if (already_computed) return;
        
        already_computed = true;
        for (int kx = 0; kx < 50; kx ++) {
            for (int ky = 0; ky < 50; ky ++) {
                Expand (kx, ky);
            }
        }
    }
    
    vector<vector<int>> pawns;
    int pawns_cnt;
    
    int Moves (int alice_turn, int last_taken, int taken_mask) {
        if (taken_mask == ((1 << pawns_cnt)-1)) return 0;
        
        int &ans = dp[alice_turn][last_taken][taken_mask];
        if (ans != -1) return ans;
        
        int x = pawns[last_taken][0], y = pawns[last_taken][1];
        ans = alice_turn? 0 : INT_MAX;
        
        for (int i = 0; i < pawns_cnt; i ++) {
            if ((1 << i) & taken_mask) continue;
            
            int nxt_x = pawns[i][0], nxt_y = pawns[i][1];
            int steps = Moves(alice_turn^1, i, taken_mask|(1 << i)) + moves[x][y][nxt_x][nxt_y];
            
            if (alice_turn) ans = max (ans, steps);
            else ans = min (ans, steps);
        }
        return ans;
    }
    
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        CalculateAll();
        memset(dp, -1, sizeof(dp));
        
        pawns = positions;
        pawns.push_back({kx, ky});
        pawns_cnt = pawns.size();
        
        return Moves (1, pawns_cnt-1, (1 << (pawns_cnt-1)));
    }
};
