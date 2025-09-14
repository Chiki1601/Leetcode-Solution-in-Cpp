class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        vector<int> arr(100001, 0);
        int l = 0, r = 0;
        int n = arrivals.size();
        int discard = 0;
        unordered_set<int> bad;

        while (r < n) {
            arr[arrivals[r]]++;
            if (arr[arrivals[r]] > m) {
                discard++;
                arr[arrivals[r]]--;
                bad.insert(r);
            }
            if (r - l + 1 == w) {
                if (bad.find(l) == bad.end()) arr[arrivals[l]]--;
                l++;
            }
            r++;
        }
        return discard;
    }
};
