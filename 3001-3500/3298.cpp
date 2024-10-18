class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long res=0;
        vector<pair<int,int>>mpp(26,{0,0});
        int l,r;
        l=0;
        r=0;
        int n=word1.size();
        int m=word2.size();
        int size=0;
        for(auto ch:word2){
            mpp[ch-'a'].second++;
        }
        while(r<n){
            while(size==m&&l<=r){
                res+=(n-r+1);
                mpp[word1[l]-'a'].first--;
                if(mpp[word1[l]-'a'].second>0&&mpp[word1[l]-'a'].first<mpp[word1[l]-'a'].second){
                    size--;
                }
                l+=1;
            }
            if(mpp[word1[r]-'a'].second>0&&mpp[word1[r]-'a'].first<mpp[word1[r]-'a'].second){
                size+=1;
            }
            mpp[word1[r]-'a'].first++;
            r+=1;
        }
        while(size==m&&l<=r){
                res+=(n-r+1);
                mpp[word1[l]-'a'].first--;
                if(mpp[word1[l]-'a'].second>0&&mpp[word1[l]-'a'].first<mpp[word1[l]-'a'].second){
                    size--;
                }
                l+=1;
        }
        return res;
    }
};
