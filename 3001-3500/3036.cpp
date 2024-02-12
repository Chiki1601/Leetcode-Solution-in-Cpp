class Solution {
    const int BASE = 5; // Base for polynomial rolling hash
    const int PRIME = 1e9 + 9; // Prime number for modulo operation
    long long power = 1;

    // Assigning numeric values to characters
    long long char_num(char ch) {
        if (ch == '1') return 1;
        if (ch == '0') return 2;
        return 3;
    }

    // Function to compute the hash value of a substring
    long long rolling_hash(const string& s) {
        long long hash_value = 0;
        for (int i = 0; i < s.size(); ++i) {
            hash_value = (hash_value * BASE) % PRIME;
            hash_value = (hash_value + char_num(s[i])) % PRIME;
        }
        return hash_value;
    }

    // Function to update hash value when sliding the window
    long long update_hash(long long old_hash, char old_char, char new_char, int length) {
        long long old_char_value = char_num(old_char);
        long long new_char_value = char_num(new_char);
        long long new_hash = ((old_hash - old_char_value * power) * BASE + new_char_value) % PRIME;
        return (new_hash + PRIME) % PRIME; // Ensure result is positive
    }


    int count(string s, string p) {
        long long hash_p = rolling_hash(p);
        string ss = s.substr(0, p.size());
        long long hash_s = rolling_hash(ss);
        int ans = hash_p == hash_s;
        for (int i = p.size(); i < s.size(); i++) {
            hash_s = update_hash(hash_s, s[i - p.size()], s[i], p.size());
            ans += hash_p == hash_s;
        }

        return ans;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        for (int i = 0; i < (int)pattern.size() - 1; ++i) {
            power = (power * BASE) % PRIME;
        }
        string s = "", p = "";
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) s.push_back('1');
            else if (nums[i + 1] == nums[i]) s.push_back('0');
            else s.push_back('-');
        }
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 1) p.push_back('1');
            else if (pattern[i] == 0) p.push_back('0');
            else p.push_back('-');
        }
        
        return count(s, p);
    }
};
