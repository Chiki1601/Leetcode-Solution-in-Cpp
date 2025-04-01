#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int BASE1 = 1823;
const int BASE2 = 8137;

class Solution {
private:
    // Fast exponentiation to compute modular inverse
    ll modPow(ll base, ll exp, ll mod) {
        ll res = 1;
        while (exp) {
            if (exp & 1) res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }

    // Function to find the longest palindromic substring using hashing
    int findLongestPalindrome(string s, string t, bool checkPrefix) {
        int maxLen = max(s.size(), t.size()) + 1;

        // Precompute power values and modular inverses
        vector<ll> powBase1(maxLen), powBase2(maxLen), invBase1(maxLen), invBase2(maxLen);
        powBase1[0] = powBase2[0] = invBase1[0] = invBase2[0] = 1;
        invBase1[1] = modPow(BASE1, MOD - 2, MOD);
        invBase2[1] = modPow(BASE2, MOD - 2, MOD);

        for (int i = 1; i < maxLen; i++) {
            powBase1[i] = powBase1[i - 1] * BASE1 % MOD;
            powBase2[i] = powBase2[i - 1] * BASE2 % MOD;
        }
        for (int i = 2; i < maxLen; i++) {
            invBase1[i] = invBase1[i - 1] * invBase1[1] % MOD;
            invBase2[i] = invBase2[i - 1] * invBase2[1] % MOD;
        }

        // Compute rolling hashes for both strings
        vector<ll> hashS1(s.size()), hashS2(s.size()), hashT1(t.size()), hashT2(t.size());
        for (int i = 0; i < s.size(); i++) {
            hashS1[i] = ((i ? hashS1[i - 1] : 0) + (s[i] - 'a' + 1) * powBase1[i]) % MOD;
            hashS2[i] = ((i ? hashS2[i - 1] : 0) + (s[i] - 'a' + 1) * powBase2[i]) % MOD;
        }
        for (int i = 0; i < t.size(); i++) {
            hashT1[i] = ((i ? hashT1[i - 1] : 0) + (t[i] - 'a' + 1) * powBase1[t.size() - i - 1]) % MOD;
            hashT2[i] = ((i ? hashT2[i - 1] : 0) + (t[i] - 'a' + 1) * powBase2[t.size() - i - 1]) % MOD;
        }

        // Lambda function to retrieve hash values of a substring from `s`
        auto getHashS = [&](int l, int r) -> pair<ll, ll> {
            if (l > r) return {0, 0};
            return {
                ((hashS1[r] - (l ? hashS1[l - 1] : 0) + MOD) % MOD) * invBase1[l] % MOD,
                ((hashS2[r] - (l ? hashS2[l - 1] : 0) + MOD) % MOD) * invBase2[l] % MOD
            };
        };

        // Lambda function to retrieve hash values of a substring from `t`
        auto getHashT = [&](int l, int r) -> pair<ll, ll> {
            return {
                ((hashT1[r] - (l ? hashT1[l - 1] : 0) + MOD) % MOD) * invBase1[t.size() - r - 1] % MOD,
                ((hashT2[r] - (l ? hashT2[l - 1] : 0) + MOD) % MOD) * invBase2[t.size() - r - 1] % MOD
            };
        };

        // Store all substrings' hashes of `t` in a hash set
        set<pair<ll, ll>> hashSet;
        hashSet.insert({0, 0});
        for (int i = 0; i < t.size(); i++) {
            for (int j = i; j < t.size(); j++) {
                hashSet.insert(getHashT(i, j));
            }
        }

        int longestPalindrome = 0;
        for (int i = 0; i < s.size(); i++) {
            int expand = -1;
            // Check for odd-length palindromes
            for (int j = 0; j <= max(i, int(s.size()) - i - 1); j++) {
                if (expand == j - 1 && i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) expand++;
                if (checkPrefix && i - j >= 0 && hashSet.count(getHashS(i - j, i - expand - 1))) longestPalindrome = max(longestPalindrome, j * 2 + 1);
                if (!checkPrefix && i + j < s.size() && hashSet.count(getHashS(i + expand + 1, i + j))) longestPalindrome = max(longestPalindrome, j * 2 + 1);
                if (expand == j) longestPalindrome = max(longestPalindrome, j * 2 + 1);
            }

            expand = -1;
            // Check for even-length palindromes
            for (int j = 0; j <= max(i, int(s.size()) - i - 2); j++) {
                if (expand == j - 1 && i - j >= 0 && i + j + 1 < s.size() && s[i - j] == s[i + j + 1]) expand++;
                if (checkPrefix && i - j >= 0 && hashSet.count(getHashS(i - j, i - expand - 1))) longestPalindrome = max(longestPalindrome, j * 2 + 2);
                if (!checkPrefix && i + j + 1 < s.size() && hashSet.count(getHashS(i + expand + 2, i + j + 1))) longestPalindrome = max(longestPalindrome, j * 2 + 2);
                if (expand == j) longestPalindrome = max(longestPalindrome, j * 2 + 2);
            }
        }
        return longestPalindrome;
    }

public:
    // Main function to return the longest palindromic substring
    int longestPalindrome(string s, string t) {
        return max(findLongestPalindrome(s, t, true), findLongestPalindrome(t, s, false));
    }
};
