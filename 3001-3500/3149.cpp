class Solution {
public:

    int findMinScore(int mask , int prevNum , vector<int> &nums , vector<vector<int>> &dp){
        int N = nums.size();

        if(__builtin_popcount(mask) == N) return dp[mask][prevNum] = abs(prevNum - nums[0]);

        if(dp[mask][prevNum] != -1) return dp[mask][prevNum];

        int minScore = 1e9;
        
        for(int currNum = 0 ; currNum < N ; currNum++){
            if(mask >> currNum & 1 ^ 1){
                int currScore = abs(prevNum - nums[currNum]) + findMinScore(mask | 1 << currNum , currNum , nums , dp);
                minScore = min(minScore , currScore);
            } 
        }

        return dp[mask][prevNum] = minScore;
    }

    vector<int> ConstructMinScorePermutation(int N , vector<int> &nums , vector<vector<int>> &dp){

        vector<int> Permutation = {0};

        for(int mask = 1 , prevNum = 0 ; Permutation.size() < N ; mask |= 1 << prevNum){
            for(int currNum = 0 ; currNum < N ; currNum++){
                if(mask >> currNum & 1 ^ 1){
                    int currScore = abs(prevNum - nums[currNum]) + dp[mask | 1 << currNum][currNum];
                    int minScore =  dp[mask][prevNum];
                    if(currScore == minScore){
                        Permutation.push_back(currNum);
                        prevNum = currNum;
                        break;
                    }
                }
            }
        }

        return Permutation;
    }
    
    vector<int> findPermutation(vector<int>& nums){      
        int N = nums.size();
        vector<vector<int>> dp(1 << N , vector<int>(N , -1));
        int minScore = findMinScore(1 , 0 , nums , dp);
        return ConstructMinScorePermutation(N , nums , dp);
    }
};
