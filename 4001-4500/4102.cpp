class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int n = s.length();
        vector<int>valid(n,0);
        for(int i=0;i<n-2;i++){
            if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c'){
                    valid[i] = 1;
                }
        }
        vector<int> next(n,0);

        next[n-1] = n;

        int y = n;
        for(int i=n-1;i>=0;i--){
            if(valid[i]){
                 y = i;
                next[i] =y;
            }else{
                next[i] = y;
            }
        }
        for(int i=0;i<n;i++){
            if(next[i] == n){
                ans += n-i;
            }else{
                ans += next[i] - i + 2;
            }
            
        }
        return ans;
    }
};
