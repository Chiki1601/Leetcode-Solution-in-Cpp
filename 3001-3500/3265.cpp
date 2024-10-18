class Solution {
public:
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                string s1 = to_string(nums[i]);
                string s2 = to_string(nums[j]);
                reverse(s1.begin(), s1.end());
                reverse(s2.begin(), s2.end());
                while(s1.size() < s2.size()) s1 += '0';

                vector<int> cnt;
                for(int k = 0; k < s1.size(); k++){
                    if(s1[k] != s2[k]) cnt.push_back(k);
                }
                if(cnt.size() == 0){
                    ans++;
                    continue;
                }
                if(cnt.size() != 2) continue;
                swap(s1[cnt[0]], s1[cnt[1]]);
                if(s1 == s2) ans++;
            }
        }

        return ans;
    }
};
