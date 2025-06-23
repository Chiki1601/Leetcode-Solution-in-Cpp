class Solution {
public:
    int countInversions(vector<int>& src, vector<int>& target) {
    unordered_map<int, int> pos;
    for (int i = 0; i < target.size(); ++i) pos[target[i]] = i;

    vector<int> arr;
    for (int i = 0; i < src.size(); ++i)
        arr.push_back(pos[src[i]]);

    // Count inversions in arr
    int n = arr.size();
    long long inv = 0;
    vector<int> BIT(n + 2, 0);

    auto update = [&](int i) {
        for (++i; i <= n; i += i & -i) BIT[i]++;
    };

    auto query = [&](int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i) res += BIT[i];
        return res;
    };

    for (int i = n - 1; i >= 0; --i) {
        inv += query(arr[i] - 1);
        update(arr[i]);
    }

    return inv;
}

    int MOD=1e9+7;
    int minSwaps(vector<int>& nums) {
        int ns=nums.size();
        bool corr=true;
        for(int i=0;i<ns-1;i++)
            {
                if(nums[i]%2==nums[i+1]%2)
                {
                    corr=false;
                    break;
                }
            }
        if(corr)
            return 0;
        
        vector<int> temp1,temp2;
        for(int i=0;i<ns;i++)
            {
                if(nums[i]%2==0)
                    temp1.push_back(nums[i]);
                else
                    temp2.push_back(nums[i]);
            }

        int n=temp1.size();
        int m=temp2.size();
        bool possible=false;
        
        if((n==m+1)|| (m==n+1) || (m==n))
            possible=true;

        if(!possible)
            return -1;
        
        vector<int> ans1,ans2;
            int i=0,j=0;
            int turn=1;
            while(i<n && j<m)
                {
                    if(turn)
                    {
                        ans1.push_back(temp1[i]);
                        i++;
                        turn=1-turn;
                    }
                    else
                    {
                        ans1.push_back(temp2[j]);
                        j++;
                        turn =1-turn;
                    }
                }
            
            if(i<n) ans1.push_back(temp1[i]);
            if(j<m) ans1.push_back(temp2[j]);

             bool takeans1=true;
            if(ans1.size()!=ns)
                takeans1=false;
                
                
       
            i=0,j=0;
            turn=1;

            
            while(i<n && j<m)
                {
                    if(turn)
                    {
                        ans2.push_back(temp2[j]);
                        j++;
                        turn =1-turn;
                    }
                    else
                    {
                        ans2.push_back(temp1[i]);
                        i++;
                        turn=1-turn;
                    }
                }
                    
           
            if(i<n) ans2.push_back(temp1[i]);
            if(j<m) ans2.push_back(temp2[j]);

            bool takeans2=true;
            if(ans2.size()!=ns)
                takeans2=false;
                
        
        int count1=countInversions(nums,ans1);
        int count2=countInversions(nums,ans2);
        return min(count1,count2);
        
    }
};
