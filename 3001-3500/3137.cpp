class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k){
        unordered_map<string, int> mp;
        int i = 0, rem = 1, n = word.size();
        string st = "";
        while(i < k){
            st += word[i];
            i++;
        }
        mp[st]++;
        while(i < n){
            string gt = "";
            for(int m = i; m < i + k; m++){
                gt += word[m];
            }
            mp[gt]++;
            rem = max(rem, mp[gt]);
            i += k;
        }
        return n/k - rem;
    }
};
