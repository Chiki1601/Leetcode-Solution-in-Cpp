class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& v, vector<int>& f) {
        priority_queue<pair<long long,int>>q;
        int n=v.size();
        map<int,long long>m;
        vector<long long>ans;
        for(int i=0;i<n;i++) {
            m[v[i]]+=f[i];
            q.push({m[v[i]],v[i]});
            while(true) {
                pair<long long,int>p=q.top();
                if(p.first==m[p.second]) {
                    ans.push_back(p.first);
                    break;
                }
                else
                    q.pop();
            }
        }
        return ans;
    }
};
