class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<long long> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int start = 0;
    int end = 1;
    int maxScore = 1;

    while (end < n) {
        ++end;
        int mid = (start + end) / 2;
        long long target = nums[mid];
        long long cost = (target * (mid - start) - (prefixSum[mid] - prefixSum[start])) + (prefixSum[end] - prefixSum[mid] - target * (end - mid));

        while (start < end && cost > k) {
            ++start;
            mid = (start + end) / 2;
            target = nums[mid];
            cost = (target * (mid - start) - (prefixSum[mid] - prefixSum[start])) + (prefixSum[end] - prefixSum[mid] - target * (end - mid));
        }

        maxScore = max(maxScore, end - start);
    }

    return maxScore;
    }
};
