class Solution {
public:
    void func(vector<vector<int>>& mat, int cols,vector <int> v,int idx,int &ans){
        if(cols==0){
            int cnt=0;
            for(int i=0;i<mat.size();i++){
                int f=1;
                for(int j=0;j<mat[i].size();j++){
                    if(mat[i][j]==1 && v[j]==0){
                        f=0;
                        break;
                    }
                }
                if(f==1){
                    cnt++;
                }
            }
            ans=max(cnt,ans);
            return;
        }
        
        for(int i=idx;i<mat[0].size();i++){
            v[i]=1;
            func(mat,cols-1,v,i+1,ans);
            v[i]=0;
        }
    }
    
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int ans=0;
        int n=mat[0].size();
        vector <int> v(n,0);
        func(mat,cols,v,0,ans);
        return ans;
    }
};
