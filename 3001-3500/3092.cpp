class Solution {
public:
  vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& f) {
    vector<long long> ans;
    unordered_map<int, long long> idToFreqMap;          // id to freq of each id unordered map
    map<long long, int> freqToIdCountMap;               // freq to id's count map - keep track of number of ids have same freq
    for(int i = 0; i < nums.size(); ++i){               // iterate over each item in nums
        if(idToFreqMap[nums[i]]){                       // When freq is non-zero then remove its occurance from the freq to id map 
            freqToIdCountMap[idToFreqMap[nums[i]]]--;   // first reduce the count of freq to id map of last freq
            if(freqToIdCountMap[idToFreqMap[nums[i]]] == 0) freqToIdCountMap.erase(idToFreqMap[nums[i]]);      // when freq to id map have current freq occuarance as zero then remove it from the map
        }
        idToFreqMap[nums[i]] += freq[i];                // update the id to freq map with the current freq
        freqToIdCountMap[idToFreqMap[nums[i]]]++;       // update the freq to id count map as per latest freq of id
        ans.push_back(freqToIdCountMap.rbegin()->first);
    }
    return ans;
}     
   
};
