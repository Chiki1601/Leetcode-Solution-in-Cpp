class Solution {
public:
    int countCompleteDayPairs(vector<int>& v) {
        int n=v.size();
        int c=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                long long s = v[i]+v[j];
                if(s%24==0)
                    c++;
            }
        }
        return c;
    }
};
