
class Solution {
public:
    struct BIT{
        int n;
        vector<int> bit;
        BIT(){}
        BIT(int _n){
            n = _n;
            bit = vector<int>(n + 1, 0);
        }
        void upd(int k, int v){
            while(k <= n){
                bit[k] += v;
                k += k&-k;
            }
        }
        int sum(int k){
            int s = 0;
            while(k > 0){
                s += bit[k];
                k -= k&-k;
            }
            return s;
        }
    };
    struct SLIDING_WINDOW{
        long long inv_count;
        deque<int> window;
        int m;
        BIT B;
        SLIDING_WINDOW(int _m){
            inv_count = 0;
            m = _m;
            B = BIT(m);
        }
        void expand(int x){
            inv_count += B.sum(m) - B.sum(x);
            
            window.push_back(x);
            B.upd(x, +1);
        }
        void shrink(){
            int x = window.front();
            inv_count -= B.sum(x - 1);
            
            window.pop_front();
            B.upd(x, -1);
        }
    };
    long long minInversionCount(vector<int>& nums, int k) {
        int n = (int)nums.size();

        set<int> S;
        for(auto x : nums){
            S.insert(x);
        }
        int m = 1;
        map<int, int> convert;
        for(auto x : S){
            convert[x] = m ++;
        }
        for(auto &x : nums){
            x = convert[x];
        }
        
        SLIDING_WINDOW SW(m);
        for(int i = 0; i < k; i ++) SW.expand(nums[i]);
        long long ans = SW.inv_count;
        for(int i = k; i < n; i ++){
            SW.shrink();
            SW.expand(nums[i]);
            ans = min(ans, SW.inv_count);
        }
        return ans;
    }
};
