class Solution {
public:
    int maximumSetSize(vector<int>& v1, vector<int>& v2) {
        set<int>s1;
        set<int>s2;
        for(auto i:v1)
            s1.insert(i);
        for(auto i:v2)
            s2.insert(i);
        int n=v1.size(),m=v2.size();
        int x=s1.size(),y=s2.size();
        int ans=min(n/2,x);
        int rem=x-ans;
        int c=0;
        for(auto i:s2) {
            if(s1.find(i)==s1.end()) {
                c++;
            } else if(rem>0) {
                c++;
                rem--;
            }
            if(c>=m/2)
                break;
        }
        return ans+c;
    }
};
