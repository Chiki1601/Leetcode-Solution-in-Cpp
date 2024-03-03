class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        int n=v.size();
        vector<int>ans;
        vector<int>v1,v2;
        v1.push_back(v[0]);
        v2.push_back(v[1]);
        for(int i=2;i<n;i++) {
            if(v1.back()>v2.back())
                v1.push_back(v[i]);
            else
                v2.push_back(v[i]);
        }
        ans=v1;
        for(auto i:v2)
            ans.push_back(i);
        return ans;
    }
};
