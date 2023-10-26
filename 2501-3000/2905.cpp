class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int index, int value) {
        int n = nums.size();
        
        int i =0;
        int j= index;
        stack<int>st;
        stack<int>st2;
        st2.push(0);
        st.push(0);
        
        while(j<n){
            
              if (nums[i]>nums[st.top()]){
                st.push(i);
            }
            else if (nums[i]<nums[st2.top()]) st2.push(i);
            
            // cout<<"j is "<<j<< "st.top() "<< st.top()<< "st2.top() "<<st2.top()<<endl;
            
            if (abs(nums[j]-nums[st.top()]) >= value){
                vector<int>v;
                v.push_back(st.top());
                v.push_back(j);
                return v;
            }
            
            else if (abs(nums[j]-nums[st2.top()]) >= value){
                vector<int>v;
                v.push_back(st2.top());
                v.push_back(j);
                return v;
            }
            i++;
            j++;

        }        
        return {-1,-1};
    }
};
