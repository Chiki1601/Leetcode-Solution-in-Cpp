class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr)
    {
        long long n = size(arr),i;
        vector<long long> nsr(n,n+1), nsl(n,-1);//we will be storing indices
        stack<long long> st1, st2;
        //Finding NSR
        st1.push(n-1);
        for(i=n-2; i>=0; i--)
        {
            while(size(st1) && arr[st1.top()] >= arr[i])
                st1.pop();
            if(size(st1))
            nsr[i] = st1.top();
            st1.push(i);
        }
        // Finding NSL
        st2.push(0);
        for(i=1; i<n; i++)
        {
            while(size(st2) && arr[st2.top()] >= arr[i])
                st2.pop();
            if(size(st2))
            nsl[i] = st2.top();
            st2.push(i);
        }
        
        vector<long long> tr(n,0), tl(n,0);
        // height of beautiful tower to the right
        tr[n-1] = arr[n-1]; 
        for(i=n-2; i>=0; i--)
        {
            if(nsr[i] == n+1)
                tr[i] = arr[i]*(n-i);
            else
            tr[i] = arr[i]*(nsr[i]-i) + tr[nsr[i]];

        }
        // height of beautiful tower to the left
        tl[0] = arr[0];
        for(i=1; i<n; i++)
        {
            if(nsl[i] == -1)
                tl[i] = arr[i]*(i+1);
            else
                tl[i] = arr[i]*(i-nsl[i]) + tl[nsl[i]];
            
            
        }
        long long res=0;
        for(i=0;i<n;i++)
            res=max(res,tl[i]+tr[i]-arr[i]); // arr[i] is counted twice so subtracting it once
            
        return res;
    }
};
