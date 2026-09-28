class Solution {
public:
    using u128=__uint128_t;
    using u64=uint64_t;
    inline static int ctz(u128 x){// assume x!=0
        u64 low=x & ULONG_MAX;
        return (low)?countr_zero(low)
                : countr_zero(u64(x>>64))+64;
    }
    static vector<int> rearrangeArray(vector<int>& nums) {
        int freq[101]={0};
        int n=nums.size();
        u128 seen=0;
        for(int x: nums){
            if(++freq[x]==1)
                seen|=((u128)1<<x);
        }
        for(int i=0; i<n; ){
            for(u128 mask=seen; mask; mask&=(mask-1)){
                int x=ctz(mask);
                if (--freq[x]==0) seen&=~((u128)1<<x);
                nums[i++]=x;
            }
        }
        return nums;
    }
};
