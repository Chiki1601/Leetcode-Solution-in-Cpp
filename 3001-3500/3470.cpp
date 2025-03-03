class Solution {
public:
 vector<long long> fact(101, LLONG_MAX);

void init(){
    if(fact[0] == 1) return;
    fact[0] = 1;
    for(int i = 1; i <= 20; i++)
        fact[i] = i * fact[i - 1];
}

class Solution {
public:
    int n, numsLeft[2];
    vector<int> ans;
    
    long long calcPerms(int odd, int even){
        long long fromOdd = fact[odd];
        long long fromEven = fact[even];

        long long totalPerms = LLONG_MAX;
        if(log10(fromOdd) + log10(fromEven) <= 18)
            totalPerms = fromOdd * fromEven;
        
        return totalPerms;
    }
    //placeOdd == -1, can place anything here, (haven't started)
    void constructArray(int placeOdd, array<vector<bool>, 2> &numsChosen, long long k){
        if(numsLeft[0] + numsLeft[1] == 0)
            return;
        
        long long nextPerms;
        if(placeOdd == -1) nextPerms = calcPerms(numsLeft[1], numsLeft[0] - 1);
        else nextPerms = calcPerms(numsLeft[1] - placeOdd, numsLeft[0] - !placeOdd);

        for(int i = 1; i <= n; i++){
            if(placeOdd == -1 || ((i & 1) == placeOdd)){
                if(!numsChosen[i & 1][i]){
                    if(k > nextPerms) k -= nextPerms;
                    else{
                        numsLeft[i & 1]--;
                        ans.push_back(i);
                        numsChosen[i & 1][i] = 1;
                        constructArray(!(i & 1), numsChosen, k);
                        break;
                    }
                }
            }
        }
    }
    vector<int> permute(int n, long long k) {
        init();
        this -> n = n;
        numsLeft[1] = (n + 1) / 2, numsLeft[0] = n / 2;
        
        array<vector<bool>, 2> numsChosen = {vector<bool> (n + 1, false), vector<bool> (n + 1, false)};
        // if evenDigits, can start from both odd or even
        int placeOdd = n % 2 ? 1 : -1;
        constructArray(placeOdd, numsChosen, k);
        
        return ans;
    }
};
};
