class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n = (int)nums.size();
        auto ok = [&](long long K) -> bool{
            long long total = 0;
            for(auto u : nums){
                total += (u + K - 1) / K;
            }
            return total <= K * K;
        };
        long long low = 1;
        long long hig = 1e9;
        while(low < hig){
            long long mid = (low + hig) / 2;
            if(ok(mid)){
                hig = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return (int)low;
    }
};
