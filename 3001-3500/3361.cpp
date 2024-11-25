class Solution {
public:
    #define ll long long
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        ll n = s.length();
        ll next[26], prev[26]; // to prevent integer overflow
        for(int i = 0; i < 26; i++){
            next[i] = nextCost[i];
            prev[i] = previousCost[i];
        }
        // Calculate cumulative costs for next and previous 
        for(int i = 1; i < 26; i++){
            next[i] += next[i - 1];
        }
        for(int i = 24; i >= 0; i--){
            prev[i] += prev[i + 1];
        }

        ll cost = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                int start = s[i] - 'a', end = t[i] - 'a';
    
                if(start < end){ // case 1
                    ll forwardCost = next[end - 1] - (start > 0 ? next[start - 1] : 0);
                    ll backwardCost = prev[0] - (start + 1 < 26 ? prev[start + 1] : 0) + (end == 25 ? 0 : prev[end + 1]);
                    cost += min(forwardCost, backwardCost);
                }
                else{ // case 2
                    ll backwardCost = prev[end + 1] - (start >= 25 ? 0 : prev[start + 1]);
                    ll forwardCost = next[25] - next[start - 1] + (end != 0 ? next[end - 1] : 0);
                    cost += min(forwardCost, backwardCost);
                }
            }
        }

        return cost;
    }
};
