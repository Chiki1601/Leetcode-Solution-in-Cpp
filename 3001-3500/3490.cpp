#define ll long long 

string gen(ll pos, ll stat, ll start, ll pr, ll sum)
{
    sting ans = to_string(pos) + '.' + to_string(stat) + '.' + to_string(start) + '.' + to_string(pr) + '.' + to_string(sum); 
    
    return ans;
}


ll find(ll pos, ll stat, ll start, string &curr, ll pr, ll sum, unordered_map<string, ll> &dp)
{
    if(pos == curr.size())
    {        
        if(pr == 0)
            return 1;
        
        if(sum == 0)
            return 0;
        
        if(pr%sum == 0)
            return 1;
        return 0;
    }        
    
    string s = gen(pos, stat, start, pr, sum); // generating string memo
    
    if(dp.find(s) != dp.end())
        return dp[s];
    
    ll dig = curr[pos] - '0';
    ll ans = 0;
    
    if(start == 0) // when the number constructed is all zeroes
    {
        if(stat == 0)
        {            
            for(ll i=0; i<dig; ++i)
            {      
                if(i == 0)
                {
                    ans += find(pos+1, 1, 0, curr, 1, sum+i, dp);
                    continue;
                }
                
                ans += find(pos+1, 1, 1, curr, pr*i, sum+i, dp);
            }
            
            
            if(dig == 0)
                ans += find(pos+1, 0, 0, curr, 1, sum+dig, dp);
            else
                ans += find(pos+1, 0, 1, curr, pr*dig, sum+dig, dp);
        }

        else if(stat == 1)
        {
            for(ll i=0; i<10; ++i)
            {
                if(i == 0)
                {
                    ans += find(pos+1, 1, 0, curr, 1, sum+i, dp);
                    continue;
                }
                
                ans += find(pos+1, 1, 1, curr, pr*i, sum+i, dp);
            }
        }

        return dp[s] = ans;
    }
    

    // case when the number constructed is not all zeroes

    if(stat == 0)
    {
        for(ll i=0; i<dig; ++i)
            ans += find(pos+1, 1, 1, curr, pr*i, sum+i, dp);

        ans += find(pos+1, 0, 1, curr, pr*dig, sum+dig, dp);
    }

    else if(stat == 1)
    {
        for(ll i=0; i<10; ++i)
            ans += find(pos+1, 1, 1, curr, pr*i, sum+i, dp);
    }

    return dp[s] = ans;
}


class Solution {
public:
    int beautifulNumbers(int l, int r) {
        
        
        string sl = to_string(l-1);
        string sr = to_string(r);
        
        unordered_map<string, ll> dp;
        ll a1 = find(0, 0, 0, sl, 1, 0, dp); // count till l-1
        
        dp.clear();
        
        ll a2 = find(0, 0, 0, sr, 1, 0, dp); // count till r
                
        return a2 - a1;
        
    }
};
