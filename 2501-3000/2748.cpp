class Solution {
public:
    int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
 
    // Return gcd of a and b
    return result;
}
    int firstDigit(int n)
{
    // Remove last digit from number
    // till only one digit is left
    while (n >= 10)
        n /= 10;
     
    // return the first digit
    return n;
}
 
// Find the last digit
int lastDigit(int n)
{
    // return the last digit
    return (n % 10);
}
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int last = lastDigit(nums[j]),first = firstDigit(nums[i]);
                if(gcd(last,first) == 1) ans++;
                
            }
        }
        return ans;
        
    }
};
