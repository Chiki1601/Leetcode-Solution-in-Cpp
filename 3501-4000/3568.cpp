class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};

        int R = classroom.size();
        int C = classroom[0].size();

        int start_r = -1, start_c = -1;
        vector<pair<int, int>> litter_item_coords; 
        map<pair<int, int>, int> litter_coord_to_idx_map;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_coord_to_idx_map[{i, j}] = litter_item_coords.size();
                    litter_item_coords.push_back({i, j});
                }
            }
        }
        
        int num_litter = litter_item_coords.size();
        if (num_litter == 0) {
            return 0; 
        }

        int target_mask = (1 << num_litter) - 1;

        vector<vector<vector<vector<int>>>> dist(
            R, vector<vector<vector<int>>>(
                   C, vector<vector<int>>(
                          energy + 1, vector<int>(
                                              1 << num_litter, -1))));

        queue<tuple<int, int, int, int>> q; 

        dist[start_r][start_c][energy][0] = 0;
        q.push({start_r, start_c, energy, 0});

        while (!q.empty()) {
            auto [r, c, current_e, mask] = q.front();
            q.pop();

            int moves = dist[r][c][current_e][mask];

            if (mask == target_mask) {
                return moves;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C && classroom[nr][nc] != 'X') {
                    if (current_e > 0) { 
                        int energy_after_move = current_e - 1;
                        int next_total_moves = moves + 1;
                        
                        int energy_at_new_cell = energy_after_move;
                        int new_mask_after_move = mask;
                        char destination_cell_char = classroom[nr][nc];

                        if (destination_cell_char == 'L') {
                            int litter_idx = litter_coord_to_idx_map.at({nr, nc});
                            new_mask_after_move |= (1 << litter_idx);
                        }
                        
                        if (destination_cell_char == 'R') {
                            energy_at_new_cell = energy;
                        }
                        
                        if (dist[nr][nc][energy_at_new_cell][new_mask_after_move] == -1 ||
                            next_total_moves < dist[nr][nc][energy_at_new_cell][new_mask_after_move]) {
                            dist[nr][nc][energy_at_new_cell][new_mask_after_move] = next_total_moves;
                            q.push({nr, nc, energy_at_new_cell, new_mask_after_move});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
