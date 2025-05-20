class Pair {
public:
    int dsum, val, idx;
    Pair(int d, int v, int i) {
        dsum = d;
        val = v;
        idx = i;
    }
};
class Solution {
public:
    int digitSum(int num) {
        int s = 0;
        while (num != 0) {
            s += num % 10;
            num /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<Pair> list;
        for (int i = 0; i < n; ++i) {
            list.push_back(Pair(digitSum(nums[i]), nums[i], i));
        }

        sort(list.begin(), list.end(), [](const Pair& a, const Pair& b) {
            if (a.dsum == b.dsum)
                return a.val < b.val;
            return a.dsum < b.dsum;
        });

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            while (list[i].idx != i) {
                swap(list[i], list[list[i].idx]);
                ++cnt;
            }
        }
        return cnt;
    }
};
