class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,long long int> mp;
        map<string,vector<pair<string,long long int>>> ans;
        long long int ma=0;
        for(long long int i=0;i<ids.size();i++)
        {
            mp[creators[i]]+=views[i];
            ma=max(ma, mp[creators[i]]);
            ans[creators[i]].push_back(make_pair(ids[i],views[i]));
            
        }
        vector<vector<string>> a;
        for(auto x:mp)
        {
            if(x.second==ma)
            {
                string p=ans[x.first][0].first;
                long long int q=ans[x.first][0].second;
                for(auto b:ans[x.first])
                {
                 if(b.second>q)
                 {p=b.first;
                  q=b.second;}
                 else if(b.second==q && p>b.first)
                     p=b.first;  
                }
                vector<string> s;
                s.push_back(x.first);
                s.push_back(p);
                a.push_back(s);
            }
                
        }
        
        return a;
    }
};
