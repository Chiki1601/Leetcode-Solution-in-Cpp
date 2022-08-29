class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
              sort(nums.begin(), nums.end());
              vector<int> ans;
        
              for(int i = 0; i < queries.size(); i++) {
                  int q = queries[i];
                  int sum = 0;
                  int count = 0;
                  
                  for(int j = 0; j < nums.size(); j++) {
                        sum = sum + nums[j];
                        if(sum > q) break;
                        count++;
                  }
                  
                  ans.push_back(count);
              }
        return ans;
    }
};
