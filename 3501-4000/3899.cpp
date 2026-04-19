#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int> sides) {
        vector<int> s = sides;
        sort(s.begin(), s.end()); // a <= b <= c
        double a = s[0], b = s[1], c = s[2];

        if (a + b <= c) return {};

        double angleA = acos((b*b + c*c - a*a) / (2*b*c)) * 180.0 / M_PI;
        double angleB = acos((a*a + c*c - b*b) / (2*a*c)) * 180.0 / M_PI;

        return {angleA, angleB, 180.0 - angleA - angleB};
    }
};
