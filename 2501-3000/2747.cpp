class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        vector<pair<int,int>> vp;
        for(auto it:logs) vp.push_back({it[1],it[0]}); //time,serverid
        sort(vp.begin(),vp.end()); //sort on basis of time
        
        int q = queries.size();
        unordered_map<int,int> mp;//to store the unique server ids in the current window

        vector<int> ans(q,0);
        vector<pair<int,int>> time(q);
        //store the indices of queries to store the answer in correct manner
        for(int i = 0;i<q;i++) time[i] = {queries[i],i}; //time,index
        sort(time.begin(),time.end()); //sort on basis of time
        
        int i = 0,j = 0; //i is the start of window and j is the end of window
        for(auto tm:time)
        {
            int curtime = tm.first;
            int ind = tm.second;
            
            int start = max(0,curtime-x); //finding the start time (like queries[i]-x), cant be less than 0
            int end = curtime; 
            
            
            while(j<m and vp[j].first<=end) //move j until the value of time in logs is not more than end
            {
                mp[vp[j].second]++; 
                j++;
            }
            while(i<m and vp[i].first<start) //move i until the value is not >= start
            {
                //removing out of window elements
                if(mp[vp[i].second]==1) mp.erase(vp[i].second); //if it is its only occurence then erase it.
                else mp[vp[i].second]--;
                i++;
            }
            ans[ind] = n - mp.size();
        }
        return ans;
    }
};
