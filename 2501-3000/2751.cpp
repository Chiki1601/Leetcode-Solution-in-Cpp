class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int n = positions.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return positions[x] < positions[y];
        });
        stack<int> s;
        for (int x : ind) {
            if (directions[x] == 'L') {
                while (!s.empty()) {
                    const int y = s.top();
                    if (healths[x] == healths[y]) {
                        healths[x] = healths[y] = 0;
                        s.pop();
                        break;
                    }
                    if (healths[x] > healths[y]) {
                        --healths[x];
                        healths[y] = 0;
                        s.pop();
                    } else {
                        healths[x] = 0;
                        --healths[y];
                        break;
                    }
                }  
            } else {
                s.push(x);
            }
        }
        vector<int> r;
        for (int x : healths) {
            if (x) {
                r.push_back(x);
            }
        }
        return r;
    }
};
