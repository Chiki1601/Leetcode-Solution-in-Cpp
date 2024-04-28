class Solution {
public:
    int addedInteger(vector<int>& v1, vector<int>& v2) {
        int a=INT_MAX,b=INT_MAX;
        for(auto i:v1)
            a=min(a,i);
        for(auto i:v2)
            b=min(b,i);
        return b-a;
    }
};
