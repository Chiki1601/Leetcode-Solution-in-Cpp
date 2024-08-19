class Solution {
public:
    static bool compare(vector<long long> v1,vector<long long> v2)
    {
        return v1[0] > v2[0];
    }
    long long maximumValueSum(vector<vector<int>>& board) {
        int r = board.size(),c = board[0].size();
        vector< vector<long long> > allPoss;
        long long res = -3000000000;
        for(int i=0;i<r;i++)
        {
            vector<pair<int,int> > vec;
            for(int j=0;j<c;j++)
                vec.push_back({board[i][j],j});
            sort(vec.begin(),vec.end(),greater< pair<int,int> >());
            int xd = vec.size();
            for(int k=0;k<min(4,xd);k++)
                allPoss.push_back({vec[k].first,i,vec[k].second});
        }
        for(int j=0;j<c;j++)
        {
            vector<pair<int,int> > vec;
            for(int i=0;i<r;i++)
                vec.push_back({board[i][j],i});
            sort(vec.begin(),vec.end(),greater< pair<int,int> >());
            int xd = vec.size();
            for(int k=0;k<min(4,xd);k++)
                allPoss.push_back({vec[k].first,vec[k].second,j});
        }
        int si = allPoss.size();
        sort(allPoss.begin(),allPoss.end(),compare);
        for(int i=0;i<min(400,si);i++)
        {
            for(int j=i+1;j<min(400,si);j++)
            {
                if(allPoss[i][1] == allPoss[j][1] || allPoss[i][2] == allPoss[j][2])
                    continue;
                for(int k=j+1;k<min(400,si);k++)
                {
                    if(allPoss[i][1] != allPoss[j][1] && allPoss[j][1] != allPoss[k][1] && allPoss[i][1] != allPoss[k][1] && allPoss[i][2] != allPoss[j][2] && allPoss[j][2] != allPoss[k][2] && allPoss[i][2] != allPoss[k][2]){
                        res = max(res,allPoss[i][0] + allPoss[j][0] + allPoss[k][0] );
                    }
                }
            }
        }
        return res;
    }
};
