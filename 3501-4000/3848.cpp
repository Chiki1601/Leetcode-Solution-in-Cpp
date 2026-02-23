#include <vector>
using namespace std;

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10);
        fact[0] = 1;

        for(int i = 1; i < 10; i++){
            fact[i] = fact[i-1] * i;
        }

        int x = n;
        int ans = 0;

        while(x != 0){
            ans += fact[x % 10];
            x /= 10;
        }

        return method(ans, n);
    }

    bool method(int ans, int n){
        vector<int> c1(10,0), c2(10,0);

        while(ans != 0){
            c1[ans % 10]++;
            ans /= 10;
        }

        while(n != 0){
            c2[n % 10]++;
            n /= 10;
        }

        return c1 == c2;
    }
};
