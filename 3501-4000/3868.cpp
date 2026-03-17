class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        if(nums1 == nums2) return 0;

        map<int,int> cnt12, cnt1, cnt2;

        for(int num : nums1) {
            cnt12[num]++;
            cnt1[num]++;
        }

        for(int num : nums2) {
            cnt12[num]++;
            cnt2[num]++;
        }

        for(auto &[x, v] : cnt12) {
            if(v & 1) return -1;
        }

        int ans = 0;

        for(auto &[x, v] : cnt12) {
            int v1 = cnt1[x];
            int v2 = cnt2[x];
            ans += abs(v1 - v2) / 2;
        }

        return ans / 2;
    }
};
