class Solution {
public:
    long long totalScore(int hp, vector<int>& damage,
                         vector<int>& requirement) {
        int h = hp;
        auto d = damage;
        auto k = requirement;
        long long z = h;
        long long ans = 0, s = 0; 
        vector<long long> p = {0};
        for (int x : d)
            p.push_back(s += x);
        for (int i = 0; i < d.size(); ++i) {
            long long t = p[i + 1] + k[i] - z;
            int ip = lower_bound(p.begin(), p.end(), t) - p.begin();
            if (ip <= i)
                ans += i - ip + 1;
        }
        return ans;
    }
};
