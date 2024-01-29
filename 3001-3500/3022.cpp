class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int n = nums.size(); //length of the array
        int ans = 0; //this will contain the 'or' of all final elements of array

        //Iterating from MSB to LSB
        for (int j = 30; j >= 0; j--) 
        {
            int cnt = 0; //count of elements which have 0 at jth bit

            //we will do & of all elements and store it here in 'cur' variable
            int cur = (1 << 30) - 1; //this is basically all last 30 bits set to 1

            int target = ans | ((1 << j) - 1); //jth bit is set 0 here, and bits from 0 to (j-1)th index are set to 1

            for (int &x : nums) 
            {
                cur &= x;
                if ((cur | target) == target) 
                {
                    cnt++;
                    cur = (1 << 30) - 1;
                }
            }

            //we have to keep the jth bit if (n-cnt) is greater than k otherwise we can remove jth bit in less than or equal to k operations
            if (n - cnt > k) 
            {
                ans |= (1 << j);
            }
        }
        return ans;
    }
};
