class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string, vector<int>> substrFreq;
        vector<string> result;

        for (int k = 0;k<arr.size(); k++) {
            string str = arr[k];
            for (int i = 0; i < str.length(); ++i) {
                for (int j = 1; j <= str.length() - i; ++j) {
                    string substr = str.substr(i, j);
                    cout<<substr<<" ";
                    int temp = substrFreq[substr].size();
                    if(temp > 0 && substrFreq[substr][temp-1] == k)  
                        continue;
                    else substrFreq[substr].push_back(k);
                }
            }
        }

        for (string& str : arr) {
            string shortestSubstr = "";
            int shortestLength = INT_MAX;

            for (int i = 0; i < str.length(); ++i) {
                for (int j = 1; j <= str.length() - i; ++j) {
                    string substr = str.substr(i, j);
                    if (substrFreq[substr].size() == 1) {
                        if (substr.length() < shortestLength || (substr.length() == shortestLength && substr < shortestSubstr)) {
                            shortestSubstr = substr;
                            shortestLength = substr.length();
                        }
                    }
                }
            }

            result.push_back(shortestSubstr);
        }

        return result;
    }
};
