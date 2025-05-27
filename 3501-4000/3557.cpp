class Solution {
public:
    int maxSubstrings(string word) {

        int len = 0;

        vector<int> arr(26, -1);
        int n = word.length();
        
        for(int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if(arr[idx] != -1 && i - arr[idx] + 1 >= 4) {
                len++;
                for(int i = 0; i < 26; i++) {
                    arr[i] = -1;
                }
            } else {
                if(arr[idx] == -1) {
                    arr[idx] = i;
                }
            }
        }

        return len;
    }
};
