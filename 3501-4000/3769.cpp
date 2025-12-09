class Solution {
public:
    int solve(int num){
        //num to binary
        string str = "";
        while(num != 0){
            if(num%2 == 0)
                str += '0';
            else
                str += '1';
            num /= 2;
        }
        
        //binary to num
        int newNum = 0;
        int power = 0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i] == '1')
                newNum += pow(2,power);
            power++;
        }
        return newNum;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<int> ans;
        vector<pair<int,int>> vp;

        for(int i=0;i<nums.size();i++){
            int val = solve(nums[i]);
            vp.push_back({val,nums[i]});
        }
        sort(vp.begin(),vp.end());
        for(auto x:vp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
