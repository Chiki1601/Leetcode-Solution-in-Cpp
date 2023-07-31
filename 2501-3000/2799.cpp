class Solution {
public:
  int countCompleteSubarrays(vector<int>& nums) {
    unordered_map<int, int> mp, all; 
    for(auto n: nums) all[n]++;      //put all elements to get the size of discrete elements
    int front = 0, back = 0, ans = 0;
    while(front < nums.size()){
        mp[nums[front]]++;
        while(back <= front && mp.size() == all.size()){
            if(--mp[nums[back]] == 0) mp.erase(nums[back]);  //update back pointer and map untill the condition satisfy
            back++;
            ans += (nums.size() - front);  //update answer - with number of array possible starting at pointer value of "back"
        }
        front++;
    }
    return ans;
}
};
