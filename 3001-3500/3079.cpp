class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0; // Initialize ans to avoid undefined behavior
        
        for(int j = 0; j < nums.size(); j++){
            int it = nums[j];
            string s = to_string(it);
            int len = s.size();
            int greater = 0;
            for(int i = 0; i < len; i++){
                int ele = s[i] - '0';
                greater = max(greater , ele);
            }
            cout<<greater<<" ";
            string new_str = "";
            for(int i = 0; i < len; i++){
                new_str += to_string(greater);
            }
            nums[j] = stoi(new_str);
        }
        
        for(int i = 0; i < nums.size(); i++){
            ans += nums[i];
        }
        return ans;
    }
};
