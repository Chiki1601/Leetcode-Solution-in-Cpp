class Solution {
public:
    bool isVowel(char c) { return c=='a'|| c=='e'||c=='i'||c=='o'||c=='u';}

    
    string sortVowels(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> rank;
        int x=1;
        string t;

        for(auto c:s){
            if(isVowel(c)){
                t.push_back(c);
                mp[c]++;
                if(rank[c]==0) rank[c]=x++;
            }
        }

        sort(t.begin(),t.end(),[&](char a,char b){
            if(mp[a]==mp[b]) return rank[a] < rank[b];
            return mp[a]>mp[b];
        });

        int ind=0;
        for(auto &c:s){
            if(isVowel(c)){
                c = t[ind++];
            }
        }
        return s;

    }
};
