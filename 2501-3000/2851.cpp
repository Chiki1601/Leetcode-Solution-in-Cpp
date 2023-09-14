struct StringAlgorithm {
	static vector<int> kmp(const std::string& s, const std::string& t) {
		int m = s.size(), n = t.size();
        std::vector<int> pi(n, 0), res;
		for (int i = 1; i < n; ++i) {
			int j = pi[i - 1];
			while (j > 0 && s[j] != s[i]) j = pi[j - 1];
			if (j == 0 && s[0] != s[i]) pi[i] = 0;
			else pi[i] = j + 1;
		}
		int j = 0;
		for (int i = 0; i < m; ++i) {
			while (j >= n || (j > 0 && s[i] != t[j])) j = pi[j - 1];
			if (s[i] == t[j]) j++;
			if (j == n) res.push_back(i - n + 1);
		}
		return res;
	}    
};
class Solution {
public:
    long long pow(long long a, long long b, const long long M) {
        long long r = 1, t = a;
        for (; b > 0; b >>= 1) {
            if (b & 1) r = (r * t) % M;
            t = (t * t) % M;
        }
        return r;
    }
    int numberOfWays(string s, string t, long long k) {
        long long n = s.size(), M = 1e9 + 7;
        auto pos = StringAlgorithm::kmp(s + s.substr(0, n-1), t);
        long long f_k[2];
        f_k[1] = (pow(n-1, k, M) + (k % 2 * 2 - 1) + M) % M * pow(n, M-2, M) % M;
        f_k[0] = (f_k[1] - (k % 2 * 2 - 1) + M) % M;
        return accumulate(pos.begin(), pos.end(), 0ll, 
            [&](long long s, long long p) { return (s + f_k[!!p]) % M; } );
    }
};
