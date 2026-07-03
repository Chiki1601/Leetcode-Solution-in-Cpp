class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& in, int fs, int fe) {
        sort(in.begin(),in.end()); 
        vector<vector<int>>merged;
        int cx=in[0][0],cy=in[0][1];
        for(int i=1;i<in.size();i++){
            int tx=in[i][0],ty=in[i][1];
            if(cy>=tx || tx==cy+1){
                cy=max(cy,ty);
            }
            else{
                merged.push_back({cx,cy});
                cx=tx,cy=ty;
            }
        }
        merged.push_back({cx,cy});

        vector<vector<int>>ans;
        for(auto& it:merged){
            int l=it[0],r=it[1];
            if(r<fs ||  l>fe)ans.push_back({l,r});
            else if(fs<=l && r<=fe)continue;
            else if(l<fs && r>fe){
                ans.push_back({l,fs-1});
                ans.push_back({fe+1,r});
            }
            else if(l<fs)ans.push_back({l,fs-1});
            else ans.push_back({fe+1,r});
        }
        return ans; 
    }
};
