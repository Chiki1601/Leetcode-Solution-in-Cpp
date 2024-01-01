class Solution {
public:
    int maximumLength(string st) {
        // Map to store the count of character sequences along with their lengths
        map<pair<char, int>, int> mps;
        int count = 0;

        // Iterate through the string
        for (int i = 0; i < st.length(); i++) {
            count = 1;
            // Store the count of each character sequence along with its length
            mps[{st[i], count}]++;

            // Check for consecutive characters
            for (int j = i; j < st.length(); j++) {
                if (st[j] == st[j + 1]) {
                    count++;
                    // Store the count of each character sequence along with its length
                    mps[{st[i], count}]++;
                } else {
                    break;
                }
            }
        }

        int ans1 = 0;

        // Iterate through the stored character sequences and their lengths
        for (auto x : mps) {
            // If a sequence appears at least three times, update the maximum length
            if (x.second >= 3) {
                ans1 = max(x.first.second, ans1);
            }
        }

        // Return the maximum length of the sequence that appears at least three times
        return (ans1 == 0) ? -1 : ans1;
    }
};


