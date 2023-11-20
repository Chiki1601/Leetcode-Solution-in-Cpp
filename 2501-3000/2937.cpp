class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int len = s1.length(); // Calculate the length of the shortest string among s1, s2, and s3
        len = min(len, (int)s2.length());
        len = min(len, (int)s3.length());

        int sum = s1.length() + s2.length() + s3.length(); // Sum of lengths of all three strings

        // Check if the first characters of s1, s2, and s3 are not the same
        if (s1[0] != s2[0] or s1[0] != s3[0] or s2[0] != s3[0]) {
            return -1; // If not the same, return -1 as it's impossible to match the first character
        }

        // Iterate through the strings until a mismatch is found
        for (int i = 0; i < len; i++) {
            if (s1[i] == s2[i] and s2[i] == s3[i]) {
                sum -= 3; // Decrement the sum by 3 for each matching character in the strings
            } else {
                break; // Break the loop when a mismatch is encountered
            }
        }

        return sum; // Return the sum of lengths of three strings minus the matched characters
    }
};

