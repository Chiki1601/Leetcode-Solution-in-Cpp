
struct custom_hash {
    static size_t splitmix64(long long x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(long long x) const {
        static const long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, vector<int>, custom_hash> mp;
        for(int l = n - 1; l >= 0; l--) {
            mp[nums[l]].push_back(l);
            for(int r = l, L = -1, R = n, D = 0; r < R && L <= R; r++) {
                int x = nums[r];
                if(mp[x].back() == r) {
                    D++;
                    int sz = mp[x].size();
                    if(sz < D) break;
                    if(sz - D - 1 >= 0)
                        R = min(R, mp[x][sz - D - 1]);
                    L = max(L, mp[x][sz - D]);
                }
                ans += L <= r;
            }
        }
        return ans;
    }
};
