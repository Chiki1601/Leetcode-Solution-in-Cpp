void check(int n , unordered_map<int,int>& m , vector<int>& ans){
        int k=INT_MAX;
        for(int i=1;i*i<=n;i++){
            if(n%i==0 and m.count(i)){
                k=min(k,m[i]);
            }

            if(i!=n/i and n%i==0 and m.count(n/i)){
                k=min(k,m[n/i]);
            }
        }
        
        if(k!=INT_MAX) ans.push_back(k);
        else ans.push_back(-1);
    }

    vector<int> assignElements(vector<int>& v, vector<int>& e){
        unordered_map<int,int> m;
        for(int i=0;i<e.size();i++){
            if(m.count(e[i])==0) m[e[i]]=i;
        }
        
        vector<int> ans;

        for(int i=0;i<v.size();i++){
            check(v[i],m,ans);
        }

        return ans;
    }
