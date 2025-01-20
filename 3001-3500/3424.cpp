class Solution {
public:
    long long cal(vector<int>& arr, vector<int>& brr){
        int n = arr.size();
        long long diff = 0;
        for(int i=0; i<n; i++){
            diff += abs(arr[i] - brr[i]);
        }
        return diff;
    }

    long long minCost(vector<int>& arr, vector<int>& brr, long long k){
        //Calculating cost without rearranging
        long long ans = cal(arr, brr);

        //Rearranging considering subarray of size 1.
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        //Calculating cost after rearranging
        ans = min(ans, cal(arr, brr)+k);
        return ans;
    }
};

//For Better Performance of code
static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}()
