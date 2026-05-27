class Solution {
public:
    using ll = long long;

    vector<int> numberOfPairs(vector<int>& nums1,
                              vector<int>& nums2,
                              vector<vector<int>>& queries) {

        int n = nums2.size();

        int blockSize = sqrt(n) + 1;
        int blocks = (n + blockSize - 1) / blockSize;

        vector<ll> a(n);
        for(int i = 0; i < n; i++) a[i] = nums2[i];

        vector<unordered_map<ll,ll>> freq(blocks);
        vector<ll> lazy(blocks, 0);

        for(int i = 0; i < n; i++) {
            freq[i / blockSize][a[i]]++;
        }

        vector<int> res;

        for(auto &q : queries) {

            // update query
            if(q[0] == 1) {

                int l = q[1];
                int r = q[2];
                ll val = q[3];

                for(int i = l; i <= r;) {

                    // full block
                    if(i % blockSize == 0 &&
                       i + blockSize - 1 <= r) {

                        lazy[i / blockSize] += val;
                        i += blockSize;
                    }
                    else {

                        int b = i / blockSize;

                        ll oldVal = a[i];

                        freq[b][oldVal]--;

                        if(freq[b][oldVal] == 0)
                            freq[b].erase(oldVal);

                        a[i] += val;

                        freq[b][a[i]]++;

                        i++;
                    }
                }
            }

            // count query
            else {

                ll total = q[1];
                ll ans = 0;

                for(int x : nums1) {

                    ll need = total - x;

                    for(int b = 0; b < blocks; b++) {

                        auto it = freq[b].find(need - lazy[b]);

                        if(it != freq[b].end())
                            ans += it->second;
                    }
                }

                res.push_back((int)ans);
            }
        }

        return res;
    }
};
