class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,long long>freq;

        for(int x:planks)freq[x]++;

        vector<long long> vals;
        for(auto&[h,c]:freq) vals.push_back(h);

        unordered_map<long long,long long> pars;
        int m=vals.size();

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                long long sum=vals[i]+vals[j];

                if(i==j){
                    pars[sum]+=freq[vals[i]]/2;
                }else{
                    pars[sum]+=min(freq[vals[i]],freq[vals[j]]);
                }
            }
        }
        long long ans=0;
        for(auto &[h,cnt]:pars){
            ans=max(ans,cnt+freq[h]);
        }

        for(auto &[h,cnt]:freq){
            ans=max(ans,cnt);
        }

        return ans;
    }
};
