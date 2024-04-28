class Solution {
public:

    using ll = long long;
    
    ll SubarraysWithAtmostKDistinctElements(vector<int>& A, int K) {
        ll subarrays = 0 , Freq[100005]{};
        for(int L = 0 , R = 0 ; R < A.size() ; R++){
            K -= Freq[A[R]]++ == 0;
            while(K < 0) K += --Freq[A[L++]] == 0;
            subarrays += R - L + 1;
        }
        return subarrays;
    }
    
    int uniqueCount(vector<int> &nums){
        return set<int>(nums.begin(),nums.end()).size();
    }
    
    int medianOfUniquenessArray(vector<int>& nums){

        ll total = (nums.size() * 1LL * (nums.size() + 1))/2;

        int low = 1 , high = uniqueCount(nums);
        int median = 1;

        while(low <= high){
            int mid = (low + high)/2;
            ll Count = SubarraysWithAtmostKDistinctElements(nums , mid);
            if(Count >= (1 + total) / 2){
                median = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return median;
    }
}; 
