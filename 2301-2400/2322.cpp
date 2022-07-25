const int N=1010,M=N*2;

int h[N],e[M],ne[M],idx;

class Solution {
public:
    int ans=1e9;
    vector<int> w;

    void add(int a,int b)
    {
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }

    int dfs(int u,int fa,int sumx,int sumy)
    {
        int res=w[u];
        for(int i=h[u];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(j==fa) continue;
            int t=dfs(j,u,sumx,sumy);
            res^=t;
            if(sumx!=-1)
            {
                int a[3]={sumy,t,sumx^t};
                sort(a,a+3);
                ans=min(ans,a[2]-a[0]);
            }
        }
        return res;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        w=nums;
        for(int i=0;i<n-1;i++)
        {
            memset(h,-1,n*4);
            idx=0;
            for(int j=0;j<n-1;j++)
            {
                if(i!=j)
                {
                    int a=edges[j][0],b=edges[j][1];
                    add(a,b),add(b,a);
                }
            }
            int x=edges[i][0],y=edges[i][1];
            int sumx = dfs(x,-1,-1,-1),sumy = dfs(y,-1,-1,-1);
            dfs(x,-1,sumx,sumy);
            dfs(y,-1,sumy,sumx);
        }
        return ans;
    }
};

