class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2) {
        
        // insert the n1 vector into the map
        map<int,int> mp;
        for( auto it : n1 ) mp[it]++;
        
        // if the min common value from n2 is present in the map
        for( auto it : n2 ){
            if( mp.find(it) != mp.end() ) return it;
        }
        
        return -1;
    }
};
