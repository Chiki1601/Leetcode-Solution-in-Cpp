#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<int> prex(n+1,0), prey(n+1,0);
        for (int i = 0; i < n; ++i) {
            prex[i+1] = prex[i];
            prey[i+1] = prey[i];
            char c = s[i];
            if (c == 'U') prey[i+1]++;
            else if (c == 'D') prey[i+1]--;
            else if (c == 'L') prex[i+1]--;
            else prex[i+1]++;
        }
        vector<int> sufx(n+1,0), sufy(n+1,0);
        for (int i = n-1; i >= 0; --i) {
            sufx[i] = sufx[i+1];
            sufy[i] = sufy[i+1];
            char c = s[i];
            if (c == 'U') sufy[i]++;
            else if (c == 'D') sufy[i]--;
            else if (c == 'L') sufx[i]--;
            else sufx[i]++;
        }
        set<pair<int,int>> ss;
        for (int i = 0; i <= n - k; ++i) {
            int x = prex[i] + sufx[i + k];
            int y = prey[i] + sufy[i + k];
            ss.insert({x, y});
        }
        return ss.size();
    }
};
