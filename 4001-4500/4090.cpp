class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        vector<vector<int>>distinct(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            vector<int>alpha(26, 0);
            int dis = 0;
            for(int j = i; j < n; j++){
                int c = s[j] - 'a';
                if(alpha[c] == 0){
                    dis++;
                    alpha[c] = 1;
                }
                distinct[i][j] = dis;
            }
        }

        int ans = 0;
        for(int j = 0; j < n - 1; j++){
            vector<int>leftFre(27,0);
            vector<int>rightFre(27,0);

            for(int i = 0; i <= j; i++){
                leftFre[distinct[i][j]]++;
            }

            for(int k = j + 1; k < n; k++){
                rightFre[distinct[j + 1][k]]++;
            }

            for(int d = 1; d <= 26; d++){
                ans += leftFre[d] * rightFre[d];
            }
        }
        return ans;
    }
};
