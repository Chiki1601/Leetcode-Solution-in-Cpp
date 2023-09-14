class Solution {
public:
    // Helper function to calculate factorial modulo moduloValue
    int f(int totalElements, int selectedElements, int moduloValue) {
        if (selectedElements == 0)
            return 1;
    
        vector<int> temp(totalElements + 1);
        temp[0] = 1;
        
        // Calculate factorial modulo moduloValue for each number up to totalElements
        for (int i = 1

; i <= totalElements; i++)
            temp[i] = (1LL * temp[i - 1] * i) % moduloValue;
        
        int result = temp[totalElements];
        result = (1LL * result * help(temp[selectedElements], moduloValue)) % moduloValue;
        result = (1LL * result * help(temp[totalElements - selectedElements], moduloValue)) % moduloValue;
        
        return result;
    }

    // Helper function to calculate modular inverse using extended Euclidean algorithm
    int help(int num, int moduloValue) {
        int mod0 = moduloValue;
        int y = 0, x = 1;
        
        while (num > 1) {
            int quotient = num / moduloValue;
            int temp = moduloValue;
            moduloValue = num % moduloValue;
            num = temp;
            temp = y;
            y = x - quotient * y;
            x = temp;
        }
        
        if (x < 0)
            x += mod0;
        
        return x;
    }
    
    int countKSubsequencesWithMaxBeauty(string inputStr, int kValue) {
        int moduloValue = 1e9 + 7;
        unordered_map<char, int> mp;
        
        for (auto ch : inputStr) {
            mp[ch]++;
        }
        
        if (mp.size() < kValue) {
            return 0;
        }
        
        vector<int> charCounts;
        for (auto charCountPair : mp) {
            charCounts.push_back(charCountPair.second);
        }
        
        sort(charCounts.begin(), charCounts.end());
        reverse(charCounts.begin(), charCounts.end());
        
        int answer = 1;
        int tt = charCounts.size();
        int lowestCharCount = charCounts[kValue - 1];
        int tll = 0, currentLowestCharCount = 0;
        
        for (int i = 0; i < tt; i++) {
            if (i < kValue) {
                answer = (1LL * answer * charCounts[i]) % moduloValue;
                if (charCounts[i] == lowestCharCount) {
                    currentLowestCharCount++;
                }
            }
            
            if (charCounts[i] == lowestCharCount) {
                tll++;
            }
        }
        
        answer = (1LL * answer * f(tll, currentLowestCharCount, moduloValue)) % moduloValue;
        return answer;
    }
};
