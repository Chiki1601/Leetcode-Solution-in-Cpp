class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors,
                      vector<int>& groupSize) {
        int n = types.size();
        int m = groupSize.size();
        vector<vector<int>> v;
        vector<int> prev = {types[0], colors[0]};
        int c = 0;
        for (int i = 0; i < n; i++) {
            vector<int> t = {types[i], colors[i]};
            if ((t[0] == prev[0]) && (t[1] == prev[1])) {
                c++;
            } else {
                prev.push_back(c);
                if (c % groupSize[prev[0]] != 0) {
                    v.push_back(prev);
                }
                prev = t;
                c = 1;
            }
        }
        prev.push_back(c);
        if (c % groupSize[prev[0]] != 0) {
            v.push_back(prev);
        }
        for (int i = 0; i < v.size(); i++) {
            v[i][2] = v[i][2] % groupSize[v[i][0]];
        }
        stack<vector<int>> st;
        for (int i = 0; i < v.size(); i++) {
            if (st.empty()) {
                st.push(v[i]);
            } else {
                vector<int> temp = st.top();
                if (temp[0] == v[i][0] && temp[1] == v[i][1]) {
                    v[i][2] += temp[2];
                    st.pop();
                    v[i][2] = v[i][2]%groupSize[v[i][0]];
                    if (v[i][2] != 0){
                        st.push(v[i]);
                    }
                }else{
                    st.push(v[i]);
                }
            }
        }
        return st.empty();
    }
};
