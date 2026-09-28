class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {

        /* Mathematical proof

        Let's take source = [a,b] and target = [c,d].

        Operation:

        a = a + b - delta
        b = delta

        Adding both:

        a + b
        = (a + b - delta) + delta
        = a + b

        Therefore, the operation only redistributes
        the sum between two elements.

        Also, since delta can be any integer, if

        a + b = c + d

        we can choose delta = d:

        b = d
        a = a + b - d = c

        Therefore, equal total sum is both necessary
        and sufficient.
        */

        long long sum1 = 0, sum2 = 0;

        // sum of source array
        for(auto it : source) sum1 += it;

        // sum of target array
        for(auto it : target) sum2 += it;

        return sum1 == sum2;
        
    }
};
