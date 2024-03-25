#define ll long long
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& id, vector<int>& freq) {
        unordered_map<ll,ll> um;
        
        vector<ll> ans;
        
        ll curmax=0;
        
        for(int i=0;i<id.size();i++){
            if(freq[i]<0){
                // if negative hain then frequency add kro
                // dont substract it my friend as -(-freq[i])= +freq[i]
                um[id[i]] += freq[i];

                // agr koi freq km hui hain toh we dont know curmax
                // toh curmax ko 0 kr do and loop lgao map me
                curmax = 0;
                if(um[id[i]]<=0){um.erase(id[i]);}

                // this loop help to get max freq again
                for(auto &val:um){
                    curmax = max(curmax,val.second);
                }
                ans.push_back(curmax);
            }
            else{
                // agr positive hain toh max element hmesha you can
                // find with taking max of last_max and current 
                // added frequency
                um[id[i]] += freq[i];

                curmax=max(curmax,um[id[i]]);

                ans.push_back(curmax);
            }
        }
                
        return ans;
    }
};
