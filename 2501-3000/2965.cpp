class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& v) {
        int n=v.size();
        map<int,int>m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                m[v[i][j]]++;
            }
        }
        int a=-1,b=-1;
        for(int i=1;i<=n*n;i++) {
            
            if(m[i]==2) {
                a=i;
            } else {
                if(m[i]==0) {
                    b=i;
                }
            }
        }
        vector<int>ans;
        
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
