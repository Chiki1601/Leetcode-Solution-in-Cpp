class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();

        int total0 = count(s.begin(), s.end(), '0');
        int total1 = n - total0;

        unordered_map<int, vector<int>> first;
        first[0] = {-1};

        int sum = 0, ans = 0;

        for(int i = 0; i < n; i++) {

            sum += (s[i] == '1' ? 1 : -1);

            for(int target : {sum, sum-2, sum+2}) {

                if(!first.count(target)) continue;

                for(int l : first[target]) {

                    int len  = i - l;
                    int diff = sum - target;

                    int ones  = (len + diff) / 2;
                    int zeros = len - ones;

                    if(diff == 0 ||
                       (diff == 2  && total0 > zeros) ||
                       (diff == -2 && total1 > ones)) {

                        ans = max(ans, len);
                        break;
                    }
                }
            }

            if(first[sum].size() < 2)
                first[sum].push_back(i);
        }

        return ans;
    }
};
