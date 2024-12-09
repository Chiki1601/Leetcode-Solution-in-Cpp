class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        sort(strength.begin(),strength.end());
        int res=INT_MAX,size=strength.size(),prev=0,energy=1;
        vector<int>permutation(size,0);
        for(int i=0;i<size;i++){
            permutation[i]=i;
        }
        do {
            int time=0;
            int x=1;
            for(int i=0;i<size;i++){
                int s=strength[permutation[i]];
                time+=ceil((double)s/(double)x);
                x+=k;
            }
            res=min(res,time);
        } while (std::next_permutation(permutation.begin(), permutation.end()));

        
        return res;
    }
};
