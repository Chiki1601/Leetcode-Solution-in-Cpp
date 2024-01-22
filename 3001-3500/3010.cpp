class Solution {
public:
    int minimumCost(vector<int>& v) {
        int n=v.size();
        int s=v[0];
        sort(v.begin()+1,v.end());
        s=s+v[1]+v[2];
        return s;
    }
};
