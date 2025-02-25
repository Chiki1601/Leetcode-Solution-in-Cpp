class Solution {
public:
    bool hasSameDigits(std::string s) {
        while (s.length() > 2) {
            std::string newbornString;
            for (size_t i = 0; i < s.length() - 1; i++) {
                int firstDigit = s[i] - '0';               
                int secondDigit = s[i + 1] - '0';          
                int newDigit = (firstDigit + secondDigit) % 10; 
              newbornString += std::to_string(newDigit); 
            }
            s = newbornString;                            
        }
        return s[0] == s[1];
    }
};
