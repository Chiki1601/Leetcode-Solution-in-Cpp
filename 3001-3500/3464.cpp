class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
    	int n = points.size();
    	
    	auto get_side = [&](const vector<int>& a) -> int {
			if(a[0] == 0) return 0;
			if(a[1] == side) return 1;
    		if(a[0] == side) return 2;
    		return 3;
    	};

    	sort(points.begin(), points.end(), [&](auto& a, auto& b) -> bool {
    		int side_a = get_side(a), side_b = get_side(b);
    		if(side_a != side_b) return side_a < side_b;
    		switch(side_a) {
    		case 0:
    			return a[1] < b[1];
    		case 1:
    			return a[0] < b[0];
    		case 2:
    			return a[1] > b[1];
    		default:
    			return a[0] > b[0];
    		}
    	});


        auto manhattan = [&](const vector<int>& a, const vector<int>& b) -> int {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
    	auto find_left = [&](int i, int L, int R, int dist) -> int {
            int Q = -1;
            while(L <= R) {
                int M = (L + R) / 2;
                if(manhattan(points[i], points[M]) >= dist) {
                    Q = M;
                    R = M - 1;
                }else if(L == R || manhattan(points[i], points[M]) <= manhattan(points[i], points[M + 1])) {
                    L = M + 1;
                }else {
                    R = M - 1;
                }
            }
            return Q;
        };

        auto best_pick = [&](int dist) -> int {
        	vector<int> next_idx(n);
        	for(int i = 0; i < n; i++) {
        		next_idx[i] = find_left(i, i + 1, n - 1, dist);
                if(next_idx[i] == -1) next_idx[i] = find_left(i, 0, i - 1, dist);
        	}
            int max_pick = 1;

            vector<bool> visited(n, false);
            for(int i = 0; i < n; i++) {
                if(visited[i] || next_idx[i] == -1) continue;
                deque<int> q {i};
                do {
                    visited[q.front()] = true;
                    while(true) {
                        int nxt = next_idx[q.back()];
                        if(nxt == -1 || manhattan(points[q.front()], points[nxt]) < dist) break;
                        q.push_back(nxt);
                    }
                    max_pick = max(max_pick, (int) q.size());
                    q.pop_front();
                }while(!visited[q[0]]);
            }
            return max_pick;
        };

        int L = 1, R = side, ans = 0;
        while(L <= R) {
        	int M = L + (R - L) / 2;
        	if(best_pick(M) >= k) {
        		ans = M;
        		L = M + 1;
        	}else {
        		R = M - 1;
        	}
        }
        return ans;
    }
};
