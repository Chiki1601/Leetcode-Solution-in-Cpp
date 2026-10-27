class Solution {
public:
    long long countMagicalPairs(string s) {
         long long n = s.size();
        map<char,vector<int>>mp;
        for(int i = 0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        long long ans = 0;
        for(int i = 0;i<n-1;i++){
            vector<long long>a,b;
            for(int j = 0;j<26;j++){
                char ch = 'a'+ j;
                if(!mp[ch].size())continue;
                auto it = lower_bound(mp[ch].begin(),mp[ch].end(),i+1);
                if(it != mp[ch].end()){
                    a.push_back(*it);
                }
                if(it != mp[ch].begin()){
                    it--;
                    b.push_back(*it);
                }
            }
            
            int x = a.size();
            int y = b.size();
            if(x == 0 || y == 0) continue;
            sort(a.begin(),a.end());
            sort(b.rbegin(),b.rend());

            for(int j = 1;j<min(x,y);j++){
                ans = ans + abs((a[j]-a[j-1])*1LL*(b[j-1]-b[j]));
            }
            if(x == y)ans = ans + abs((n-a[x-1])*1LL*(b[y-1]+1));
            else if(x < y)ans = ans + abs((n-a[x-1])*1LL*(b[x-1]-b[x]));
            else ans = ans + abs((a[y]-a[y-1])*1LL*(b[y-1]+1));
        }
        return ans;
    }
};
