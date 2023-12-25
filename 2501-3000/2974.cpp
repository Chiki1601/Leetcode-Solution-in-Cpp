class Solution {
public:
    vector<int> numberGame(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n;i+=2) {
            swap(v[i],v[i+1]);
        }
        return v;
    }
};
