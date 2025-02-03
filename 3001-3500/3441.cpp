pair<int, char> dp[50'001][26][4];
const pair<int, char> GOOD = {0, '~'};
const pair<int, char> BAD = {-1, '~'};
class Solution {
public:
    string minCostGoodCaption(string caption) {
        int n = caption.size();
        if(n < 3) return "";
        for(char last = 0; last < 26; last++) {
            for(int cnt = 0; cnt <= 3; cnt++) {
                // Base case
                dp[n][last][cnt] = (cnt >= 3) ? GOOD : BAD;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            int captionChar = (caption[i] - 'a');
            for(char last = 0; last < 26; last++) {
                for(int cnt = 0; cnt <= 3; cnt++) {
                    char bestChar = '~';
                    int bestCost = -1;
                    for(int ch = 0; ch < 26; ch++) {
                        int changeCost = abs(captionChar - ch);
                        // if there was a previous char and its consecutive ends at cnt < 3, continue;
                        if(1 <= cnt && cnt < 3 && ch != last) continue;
                        int nextCnt = min(3, 1 + (ch == last) * cnt);
                        
                        pair<int, char> res = dp[i + 1][ch][nextCnt];
                        if(res.first == -1) continue; // invalid
                        // if haven't found any, or this is better
                        if(bestCost == -1 || changeCost + res.first < bestCost) {
                            bestCost = changeCost + res.first;
                            bestChar = ch;
                        }
                    }
                    dp[i][last][cnt] = {bestCost, bestChar};
                }
            }
        }
        string res(n, '0');
        pair<int, char> curr = dp[0][0][0];
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            res[i] = curr.second;
            if(i != n-1) {
                int nextCnt = min(3, 1 + (i > 0 && res[i] == res[i - 1]) * cnt);
                cnt = nextCnt;
                curr = dp[i + 1][res[i]][nextCnt];
            }
        }
        for(char& c : res) c += 'a';
        return res;
    }
};
