#define ll long long int
class Solution {
public:
    vector<ll> preh, preb;
   int mod = 1e9 + 7;
    int base = 31;    
    void pprocess(vector<int>& nums){
        int n = nums.size();
        preh.resize(n + 1, 0);
        preb.resize(n + 1, 1);       
        for(int i = 1; i <= n; ++i){
            preh[i] = (preh[i-1] * base + nums[i-1]) % mod;
            preb[i] = (preb[i-1] * base) % mod;
        }
    }

    ll getHash(int l, int r){
        ll hash = preh[r+1] - (preh[l] * preb[r-l+1]) % mod;
        if(hash < 0) hash += mod;
        return hash;
    }

    bool compare(vector<int>& nums, int start1, int start2, int len){
        return getHash(start1, start1+len-1) == getHash(start2, start2+len-1);
    }

    int beautifulSplits(vector<int>& nums){
        int n = nums.size();
        int count = 0;
        pprocess(nums);
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int len1 = i;       
                int len2 = j - i;   
                int len3 = n - j;   
                bool ans1 = false, ans2 = false;
                if(len1 <= len2 && compare(nums, 0, i, len1)){
                    ans1 = true;
                }
                if(len2 <= len3 && compare(nums, i, j, len2)){
                    ans2 = true;
                }
                if(ans1 || ans2){
                    count++;
                }
            }
        }
        return count;
    }
};
