class Solution {
public:
    #define ll long long
    ll func(vector<ll> &pos, vector<ll> &neg, ll ind1, ll ind2, ll fg,vector<vector<vector<ll>>> &dp){
        if(ind1==pos.size()&& ind2==neg.size())
        return 0;

        if(dp[fg][ind1][ind2]!=-1)
        return dp[fg][ind1][ind2];

        ll cord;
        if(fg)cord=pos[ind1-1];
        else cord=neg[ind2-1];

        ll ans=1e18;
        if(ind1<pos.size())
        ans=min(ans, (ll)(abs(cord-pos[ind1])*(pos.size()+neg.size()-ind1-ind2))+func(pos,neg,ind1+1,ind2,1,dp));

        if(ind2<neg.size())
        ans=min(ans, (ll)(abs(cord-neg[ind2])*(pos.size()+neg.size()-ind1-ind2))+func(pos,neg,ind1,ind2+1,0,dp));

        return dp[fg][ind1][ind2]=ans;
    }
    long long elevatorRequests(int n, int start, vector<int>& v) {
        sort(v.begin(),v.end());
        // debug(v);
        vector<ll> neg,pos;
        ll nn=v.size();
        for(ll i=0;i<nn;i++){
            if(v[i]==start)
            continue;
            if(v[i]<start)neg.push_back(v[i]);
            else pos.push_back(v[i]);
        }
        pos.insert(pos.begin(),start);
        reverse(neg.begin(),neg.end());
        // debug(pos,neg)
        vector<vector<vector<ll>>> dp(2,vector<vector<ll>> (pos.size()+1,vector<ll>(neg.size()+1,-1)));
        ll ans=func(pos,neg,1,0,1,dp);
        return ans;
    }
};
