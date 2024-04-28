class Solution {
public:
    using ll = long long;
    
    ll atMostK(vector<int>& A, int K) {
        ll i = 0, res = 0;
        unordered_map<int, ll> count;
        for (int j = 0; j < A.size(); ++j) {
            if (!count[A[j]]++) K--;
            while (K < 0) {
                if (!--count[A[i]]) K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
    
    ll uniqueCount(vector<int> &nums){
        set<int> set;
        for(int &num : nums) set.insert(num);
        return set.size();
    }
    
    int medianOfUniquenessArray(vector<int>& nums){
        ll n = nums.size();
        ll low = 1 , high = uniqueCount(nums) , median = 1;
        ll total = (n * (n+1))/2;
        while(low <= high){
            int mid = (low + high)/2;
            ll count = atMostK(nums , mid);
            if(count >= (total+1)/2){
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



    
    
