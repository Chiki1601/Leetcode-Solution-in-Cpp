vector<int> isPrime;

void generatePrimes() {
    if (!isPrime.empty()) return;
    isPrime.resize(1e5 + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= 1e5; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= 1e5; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

class Solution {
public:
    int minOperations(int n, int m) {
        generatePrimes();
        if (isPrime[n] || isPrime[m]) return -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_set<int> visited;

        q.push({n, n});
        while (!q.empty()) {
            auto [steps, curr] = q.top();
            q.pop();

            if (visited.count(curr)) continue;
            visited.insert(curr);

            if (curr == m) return steps;

            string s = to_string(curr);
            for (int i = 0; i < s.length(); i++) {
                char original = s[i];

                if (s[i] < '9') {
                    s[i]++;
                    int next = stoi(s);
                    if (!isPrime[next] && !visited.count(next)) {
                        q.push({steps + next, next});
                    }
                    s[i] = original;
                }

                if (s[i] > '0' && !(i == 0 && s[i] == '1')) {
                    s[i]--;
                    int next = stoi(s);
                    if (!isPrime[next] && !visited.count(next)) {
                        q.push({steps + next, next});
                    }
                    s[i] = original;
                }
            }
        }
        return -1;
    }
};
