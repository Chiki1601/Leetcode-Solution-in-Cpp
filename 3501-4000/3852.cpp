class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        // 4->1 1->2 3->5
        vector<int>sortedUniqueNums;
        for(auto it:freq)sortedUniqueNums.push_back(it.first);
        sort(sortedUniqueNums.begin(),sortedUniqueNums.end());
        for(int i=0;i<sortedUniqueNums.size();i++){
            for(int j=i+1;j<sortedUniqueNums.size();j++){
                int x=sortedUniqueNums[i];
                int y=sortedUniqueNums[j];
                if(freq[x]!=freq[y])return {x,y};
            }
        }
        return {-1,-1};
    }
};
