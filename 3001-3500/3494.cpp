class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        
        vector<long long> sPre(n, 0);
        for (int i = 1; i < n; i++) 
            sPre[i] = sPre[i - 1] + skill[i];

        long long tSum = (long long)skill[0] * mana[0];

        for (int j = 1; j < m; j++) {
            long long tMax = (long long)skill[0] * mana[j];
            for (int i = 1; i < n; i++) {
                long long tDiff = sPre[i] * mana[j - 1] - sPre[i - 1] * mana[j];
                if (tDiff > tMax) 
                    tMax = tDiff;
            }
            tSum += tMax;
        }
        return tSum + sPre[n - 1] * mana[m - 1];
    }
};
