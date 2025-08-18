#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
class Solution {
public:
    bool get_bit(int n, int pos) {
        return n & (1 << pos);
    }

    void generate_palindromes(vector<ll> &candidates, const vector<int> &chosen_elements) {
        vector<int> half;
        int odd_element = -1;
        for (auto val: chosen_elements) {
            if (val % 2) {
                odd_element = val;
            }
            int count = val / 2;
            while (count--) {
                half.push_back(val);
            }
        }
        do {
            ll candidate = 0LL;
            for (auto val: half) {
                candidate = 10LL * candidate + val;
            }
            if (odd_element != -1) {
                candidate = 10LL * candidate + odd_element;
            }
            for (int i = (int) half.size() - 1; i >= 0; i--) {
                int val = half[i];
                candidate = 10LL * candidate + val;
            }
            candidates.push_back(candidate);
        } while (next_permutation(all(half)));
    }

    ll specialPalindrome(ll n) {
        vector<ll> candidates;
        vector<int> elements{1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < (1 << 9); i++) {
            vector<int> chosen_elements;
            for (int pos = 0; pos < 9; pos++) {
                if (get_bit(i, pos)) {
                    chosen_elements.push_back(elements[pos]);
                }
            }
            int odd_count = 0;
            int total_length = 0;
            for (auto val: chosen_elements) {
                if (val % 2) odd_count++;
                total_length += val;
            }
            if (odd_count > 1) continue;
            if (total_length >= 17) continue;
            generate_palindromes(candidates, chosen_elements);
        }
        sort(all(candidates));
        auto it = upper_bound(all(candidates), n);
        if (it != candidates.end()) {
            return *it;
        }
        return -1;
    }
};
