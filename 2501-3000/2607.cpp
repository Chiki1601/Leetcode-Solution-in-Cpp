class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans = 0;
        
        int n = arr.size();
    
        k = __gcd(k , n);
        
        //due to circular array the gap k will be converted to gcd of
        // k and n by observation (check for n = 15 , k = 6 , and find out)
        for(int i=0;i<k;i++) {
            vector<int> v;
            
            for(int j = i;j<n;j+=k) {
                v.push_back(arr[j]);
            }
            
            sort(v.begin() , v.end());
            //taking the mid value of the sorted array to get the 
            //median as it will require minimum operation to convert 
            //all elements to the medain value
            long long midv = v[v.size()/2];
            
            for(int j=i;j<n;j+=k) {
                ans += abs(midv - arr[j]);
            }
        }
        
        
        return ans;
    }
};
