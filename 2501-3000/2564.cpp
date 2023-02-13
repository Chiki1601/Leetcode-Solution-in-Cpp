class Solution {
private:
    long long StoNum(string x){     // utilitty to convert binary string to number
        long long res=0;
        for(int i=0;i<x.size();i++){
            res*=2;
            if(x[i]=='1')   res+=1;
        }
        return res;
    }
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        
        vector<long long> res;
        unordered_map<long long,pair<int,int>> found;
        int n=queries.size();
        vector<vector<int>> ans(n,vector<int>(2,-1));
        
        for(auto& q:queries){
            long long first=q[0],second=q[1];
            res.push_back(first^second);
        }
        
        for(int i=0;i<s.size();i++){
            set<pair<int,string>> avail;
            for(int j=i;j<min((int)s.size(),i+33);j++){
                long long val=StoNum(s.substr(i,j-i+1));
                avail.insert({val,s.substr(i,j-i+1)});
            }
            
            for(auto& av:avail){
                if(!found.count(av.first))  found[av.first]={i,av.second.size()+i-1};       //not seen till now.
                
                int lenAlready=found[av.first].second-found[av.first].first+1;
                
                if(lenAlready>av.second.size()) found[av.first]={i,av.second.size()+i-1};       // lesser len available
            }
        }
        

        
        for(int i=0;i<n;i++){
            if(found.count(res[i])){        // if such a number exist in the string.
                ans[i]={found[res[i]].first,found[res[i]].second};
            }
        }
        return ans;
                
        
    }
};
