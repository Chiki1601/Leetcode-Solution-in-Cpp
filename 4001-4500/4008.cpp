class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        long long org=0;
        long long cs=0;
        int n=monsters.size();
        vector<long long>bonus(n+1,0);
        for(auto& boost:boosts){
            bonus[boost[0]]+=boost[2];
            bonus[boost[1]+1]-=boost[2];
        }
        
        for(int i=1;i<=n;i++){
            bonus[i]=bonus[i-1]+bonus[i];
        }
        long long drag=0;
        for(int i=0;i<n;i++){
            long long diff=cs+bonus[i]-monsters[i];
            if(diff<0){
                org+=abs(diff);
                org+=drag;
                cs+=abs(diff);
                drag=0;
            }
            cs-=monsters[i];
            if(cs<0){
                drag+=abs(cs);
                cs=0;
                
            }
            // cout<<org<<" "<<cs<<endl;
        }
        return org;
    }
};
