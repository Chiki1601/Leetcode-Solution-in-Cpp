class Solution {
public:
   bool isGood(vector<int>& nums) {
    vector<int> v(202, 0);
    for(auto n:nums) v[n]++;
    if(v[nums.size()-1] != 2) return false;
    for(int i = 1; i < nums.size()-1; ++i){
        if(v[i] != 1) return false;
    }
    return true;
}
};
