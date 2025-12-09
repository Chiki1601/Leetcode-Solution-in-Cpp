class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2,   int k) {
        int n = (int)technique1.size();
        vector<int> v;
        for(int i = 0; i < n; i ++){
            v.push_back(i);
        }
        sort(v.begin(), v.end(), [&](const int &i, const int &j){
            return (technique1[i] - technique2[i]) > (technique1[j] - technique2[j]);
        });
        long long ans = 0;
        for(int i = 0; i < k; i ++){
            ans += technique1[v[i]];
        }
        for(int i = k; i < n; i ++){
            ans += max(technique1[v[i]], technique2[v[i]]);
        }
        return ans;
    }
};
