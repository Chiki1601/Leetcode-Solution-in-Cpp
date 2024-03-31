class Solution {
public:
   int sumOfTheDigitsOfHarshadNumber(int x) {
    int sum = 0;
    for( int n = x; n > 0; n = n/10){
        sum += (n%10);
    }
    return (x % sum == 0)? sum: -1;
}
};
