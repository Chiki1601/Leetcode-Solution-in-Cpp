class Solution {
public:
        vector<int> a;
    while(i<nums.size()){ 
        int j= i+1;
        while(j<nums.size()){
            int sum=nums[i]+nums[j];
            if(sum==target) {
                a.push_back(i);
                a.push_back(j);
                return a;
            }
            j++;
        }
        i++;
        }
    a.push_back(-1);
    return a;
}
};
