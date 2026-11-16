#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();

        vector<vector<int>> left(n+1, vector<int>(20, 0)), right(n+2, vector<int>(20, n+1));
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> leftOcc(n+1, 0), leftIdx(maxi+1, 0);

        for(int i = 1; i <= n; ++i){
            leftOcc[i] = leftIdx[nums[i-1]];
            leftIdx[nums[i-1]] = i;
            for(int b = 0; b < 20; ++b){
                if(!((nums[i-1] >> b) & 1)){
                    left[i][b] = i;
                }else{
                    left[i][b] = left[i-1][b];
                }
            }
        }

        for(int i = n; i >= 1; --i){
            for(int b = 0; b < 20; ++b){
                if(!((nums[i-1] >> b) & 1)){
                    right[i][b] = i;
                }else{
                    right[i][b] = right[i+1][b];
                }
            }
        }

        for(int i = 1; i <= n; ++i){
            ll L = leftOcc[i];
            ll R = n + 1; 
            
            for(int b = 0; b < 20; ++b){
                if(!((nums[i-1] >> b) & 1)){
                    continue;
                }
                L = max(L, (ll)left[i][b]);
                R = min(R, (ll)right[i][b]);
            }
            
            ans += (R - i) * (i - L);
        }
        
        return ans;
    }
};

// int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
// }
