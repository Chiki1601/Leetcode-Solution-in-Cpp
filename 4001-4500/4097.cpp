#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();

        int mn = INT_MAX;

        for (int i = 0; i < n; i += 2) {
            int a = nums[i];
            int b = nums[i + 1];

            cout << a << ";" << b << endl;

            int x = stoi(to_string(a) + to_string(b));

            mn = min(mn, x);
        }

        return mn;
    }
};
