class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        // convert[i] = 2^i, so convert[0..25] holds powers of two for 'a' to 'z'
        vector<long long> convert(26, 0);
        long long base = 1;

        for(int i = 0; i < 26; i++){
            convert[i] = base;
            base *= 2;
        }

        vector<string> res;

        for(int n : nums){
            string cur = "";

            // greedily break n into powers of two (its binary representation),
            // largest power first, mapping each power to a letter
            while(n > 0){
                int i = 25;

                while(convert[i] > n){
                    i--;
                }

                cur += (char)('a' + i);
                n -= convert[i];
            }

            res.push_back(cur);
        }

        return res;
    }
};
