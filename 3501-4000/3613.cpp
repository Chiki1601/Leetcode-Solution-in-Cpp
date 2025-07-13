class DisjointSet{
public:
    vector<int>parent;
    vector<int>rank;

    DisjointSet(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findupar(int i){
        if(parent[i]==i)return i;
        return parent[i]=findupar(parent[i]);
    }

    void unionbyrank(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v)return ;
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    int components(){
        unordered_set<int>roots;
        for(int i=0;i<parent.size();i++){
            roots.insert(findupar(i));
        }
        return (int)roots.size();
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int low=0;
        int high=0;
        for(auto & p:edges){
            high=max(high,p[2]);
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            DisjointSet dsu(n);
            for(auto & edge:edges){
                int u=edge[0],v=edge[1],w=edge[2];
                if(w<=mid){
                    dsu.unionbyrank(u,v);
                }
            }
            int compo=dsu.components();
            if(compo<=k){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
