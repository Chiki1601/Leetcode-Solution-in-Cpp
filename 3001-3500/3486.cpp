class Solution {
public:
    int valueCount[50001];
    vector<int>path,pathLengths;
    int maxLength,minNodes;
    void dfs(int node, int parent, int pathPointer, int pathLength, int nodes,int duplicates, vector<vector<pair<int,int>>> &g, vector<int>& nums) 
    {
        path.push_back(nums[node]);
        valueCount[nums[node]]++;
        if(valueCount[nums[node]]>1)
           duplicates++;    
        nodes++;   
        int oldPointer=pathPointer;
        while(duplicates>1) {
            nodes--;
            pathLength-=pathLengths[pathPointer];
            valueCount[path[pathPointer]]--;
            if(valueCount[path[pathPointer]]>=1)
                duplicates--;
            pathPointer++;    
        }   
        if(pathLength>maxLength || (pathLength==maxLength && minNodes>nodes)) {
            minNodes=nodes;
            maxLength=pathLength;
        }
        for(auto &next:g[node]) {
            if(next.first==parent)
               continue;
            pathLengths.push_back(next.second);  
            dfs(next.first,node,pathPointer,pathLength+next.second,nodes,duplicates,g,nums); 
            pathLengths.pop_back();  
        }
        path.pop_back();
        valueCount[nums[node]]--;
        while(oldPointer<pathPointer)
           valueCount[path[oldPointer++]]++;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n=nums.size();
        maxLength=0,minNodes=0;
        memset(valueCount, 0, sizeof(valueCount));
        vector<vector<pair<int,int>>>g(n);
        for(auto &edge:edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        dfs(0,-1,0,0,0,0,g,nums);
        return {maxLength, minNodes};
    }
};
