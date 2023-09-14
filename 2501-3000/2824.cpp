class Solution {
public:
    int countPairs(vector<int>& v, int target) {
        int ans = 0,i,j,n=v.size();
        for(i = 0; i < n; i++){
            for(j = i+1; j < n; j++){
                if(v[i]+v[j] < target){
                    ans++;
                }
            }
        }
        return ans;
    }
};
