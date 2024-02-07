class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end(),comp);
        int ans=0;
        for(int i=0; i<n; i++){
            int minY=INT_MIN;
            for(int j=i+1; j<n; j++){
                if(v[j][1]<=v[i][1]){
                    if(v[j][1]>minY)ans++;
                    minY=max(minY, v[j][1]);
                }
            }
        }
        return ans;
    }
};
