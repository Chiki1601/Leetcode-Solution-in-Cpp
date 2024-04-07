class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int n=v.size();
        int m=1;
        for(int i=1;i<n;i++) {
            int c=1;
            for(int j=i-1;j>=0;j--) {
                if(v[j+1]>v[j]) {
                    c++;
                }
                else
                    break;
            }
            m=max(m,c);
        }
        for(int i=1;i<n;i++) {
            int c=1;
            for(int j=i-1;j>=0;j--) {
                if(v[j+1]<v[j]) {
                    c++;
                } else
                    break;
            }
            m=max(m,c);
        }
        
        return m;
    }
};
