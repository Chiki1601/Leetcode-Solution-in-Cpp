class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
       int n=word.size();
       unordered_map<string,int>mp;
        for(auto it:forbidden){
            mp[it]=1;
        }
        string ans;
        int fans=0;
        for(int i=0;i<n;i++){
            ans+=word[i];
            int m=ans.size();
            bool is=true;
            int idx=-1;
            for(int j=max(0,m-10);j<m;j++){
                string curr=ans.substr(j);
                if(mp.find(curr)!=mp.end()){
                    idx=j;
                }
            }
            if(idx!=-1){
                ans=ans.substr(idx+1);
            }
            fans=max(fans,(int)ans.size());
        }
        return fans;
    }
};
