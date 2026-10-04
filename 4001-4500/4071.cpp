class Solution {
public:
    int dist(char a, char b){
        int x = abs((a-'0') - (b-'0'));
        return min(x, 10-x);
    }

    int minRotations(int n, string s) {
        vector<int> pref(n), suf(n);

        pref[0] = dist('0', s[0]);

        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + dist(s[i-1], s[i]);
        }

        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i+1] + dist(s[i], s[i+1]);
        }

        int mn = pref[n-1];

        for(int k = 0; k < n; k++){
            int cur;

            if(k == 0){
                cur = dist('0', s[n-1]) + suf[0];
            }
            else{
                cur = pref[k-1] + dist(s[k-1], s[n-1]) + suf[k];
            }

            mn = min(mn, cur);
        }

        return mn;
    }
};
