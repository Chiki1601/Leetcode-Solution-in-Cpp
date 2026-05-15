class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> st;
        for (auto& v : points) {
            st.insert(v);
        }
        if(st.count(target)){
            return 0;
        }
        if(points.size() == 1){
            return -1;
        }
        int ans = 0;
        while (!st.count(target)) {
            int n = points.size();
            vector<vector<int>> t;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    vector<int>& v1 = points[i];
                    vector<int>& v2 = points[j];
                    if(v1 == v2){
                        continue;
                    }
                    int x = (v1[0] + v2[0]) / 2;
                    int y = (v1[1] + v2[1]) / 2;
                    int z = (v1[2] + v2[2]) / 2;
                    if (!st.count({x, y, z})) {
                        t.push_back({x, y, z});
                    }

                }
            }
            if (t.size() == 0) {
                return -1;
            }
            for (auto& k : t) {

                if (!st.count(k)) {
                    points.push_back(k);
                    st.insert(k);
                }
            }
            ans++;
        }
        return ans;
    }
};
