class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int count =0;
        unordered_map<int,int> ans;
        unordered_map<int,vector<int>> jp;
        int sum =0;
        for(int i=0;i<s.size();i++){
            sum=0;
            for(int j=i;j<s.size();j++){
                ans[s[j]]++;
                auto f = ans.begin();
                bool kp = true;
                
                for(auto d:ans){
                    if(f->second!=d.second){
                        kp=false;
                    }
                }
                
                if(kp){
                    jp[i].push_back(j);
                }
            }
            ans.clear();
            i+=sum;
            
        }
        
        vector<int> d(s.size(),0);
        
        for(int i=0;i<s.size();i++){
            int c;
            if(i==0){
                c=0;
            }else{
                c = d[i-1];
            }
            
            for(int j=0;j<jp[i].size();j++){
                if(d[jp[i][j]]==0){
                   d[jp[i][j]] += 1+c; 
                }else{
                    d[jp[i][j]] = min(d[jp[i][j]],1+c);
                }
                
            }
            
        }
        
        return d[s.size()-1];
        
    }
};
