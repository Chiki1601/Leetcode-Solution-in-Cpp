class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size(), oddLength = 0, result = n;
        vector<int> lengths, freq(26);
        for (string& word: words) {
            lengths.push_back(word.size());
            oddLength += lengths.back() & 1;
            for (char ch: word) {
                freq[ch - 'a']++;
            }
        }
        int oddFreq = count_if(freq.begin(), freq.end(), [](int x) { return x & 1; });
        int remaining = max(0, oddFreq - oddLength);
        sort(lengths.begin(), lengths.end(), greater<int>());
        for (int i = 0; i < n && remaining > 0; i++) {
            remaining -= lengths[i] - (lengths[i] & 1);
            result--;
        }
        return result;
    }
};
