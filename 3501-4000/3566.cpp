class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        
        for(const auto& num: nums){
            if(target%num != 0) return false;
        }

        long long partition2 = 1;

        if(dfs(0, nums, 1, target)){
            if(s.size() == 0) return false;

            for(int i=0;i<n;++i){
                if(s.find(i) == s.end()){
                    partition2 *= nums[i];
                }
            }

        }
        return partition2 == target ? true : false;
    }
private:
    unordered_set<int> s;

    bool dfs(int start, vector<int>& nums, long long currTarget, long long& target){
        if(start >= nums.size()){
            if(currTarget == target){
                return true;
            }
            return false;
        }

        if(currTarget > target) return false;

        bool take = dfs(start+1, nums, currTarget*nums[start], target);
        
        if(take){
            s.insert(start);
            return true;
        }

        bool notTake = dfs(start+1, nums, currTarget, target);

        return notTake;
    }
};
