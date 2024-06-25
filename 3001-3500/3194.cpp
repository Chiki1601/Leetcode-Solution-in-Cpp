class Solution {
public:
    static double minimumAverage(vector<int>& nums) {
        int n=nums.size();
        char freq[51]={0}, xMin=50, xMax=1;
        double sum=0;
        for(char x: nums){
            freq[x]++;
            xMin=min(xMin, x);
            xMax=max(xMax, x);
        }
        double minAv=50;
        for(char i=xMin, j=xMax; n>0; n-=2){
            while (i<j && freq[i]==0) i++;
            while (i<j && freq[j]==0) j--;
            if (i > j) break;
            minAv=min({minAv, double(i+j)/2 });
            if (--freq[i]==0) i++;
            if (--freq[j]==0) j--;
        }
        return minAv;
    }
};




auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
