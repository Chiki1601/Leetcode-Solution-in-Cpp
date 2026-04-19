class Solution {
public:
    int MOD = 1e9 + 7;
    int MAX = 20006;
    vector<long long> pow;

    void precompute(){
        pow[0] = 1;
        for(int i=1;i<MAX;i++){
            pow[i] = (pow[i-1]*2)%MOD;
        }
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        pow.resize(MAX);
        int n = nums1.size();
        precompute();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums1[i], nums0[i]});
        }
        sort(v.begin(), v.end(), [&](pair<int, int> & p1, pair<int, int> & p2){
            int a1 = p1.first;
            int a2 = p1.second;
            int a3 = p2.first;
            int a4 = p2.second;
            string s1(a1,'1');
            string s2(a3,'1');
            string s3(a2,'0');
            string s4(a4,'0');

            s1 += s3;
            s2 += s4;

            return s1 + s2 > s2 + s1;
        });
        int ans = 0;
        for(auto& p : v){
            int a = p.first;
            int b = p.second;
            int sum = a + b;
            ans = ((1LL*ans*pow[sum])%MOD + (((pow[a]-1 + MOD)%MOD)*pow[b])%MOD)%MOD;
        }
        return ans;
    }
};
