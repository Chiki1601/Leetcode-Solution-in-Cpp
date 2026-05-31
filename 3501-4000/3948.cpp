class Solution {
    using ll=long long;
public:
    vector<int> maximumMEX(vector<int>& a) {
        ll n=a.size();
        vector<ll>sm(n);
        
        set<ll>s;
        for(int i=0;i<=n;i++)s.insert(i);
        for(int i=n-1;i>=0;i--){
            if(s.find(a[i])!=s.end())s.erase(a[i]);
            sm[i]=*s.begin();
        }

        vector<int>ans;
        set<ll>st;
        for(int i=0;i<=sm[0];i++){
            st.insert(i);
        }

        ll v=sm[0];
        for(int i=0;i<n;i++){
            st.erase(a[i]);
            ll p=*st.begin();
            if(p>=v){
                ans.push_back(p);
                st.clear();
                
                if(i<n-1){
                    v=sm[i+1];
                    for(int k=0;k<=v;k++){
                        st.insert(k);
                    }
                }
            }
        }
        return ans;
        
        
    }
};
