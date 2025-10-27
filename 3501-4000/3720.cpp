class Solution {
    char nextBig(char ch, map<char, int> &mp){
        for(auto [k, f]: mp){
            if(k>ch && f>0){
                return k;
            }
        }
        return '#';
    }
public:
    string lexGreaterPermutation(string s, string target) {
        string s1=s;
        sort(s1.begin(), s1.end());
        reverse(s1.begin(), s1.end());
        if(s1 <= target){
            return "";//to check if finding such string is possible or not!!
        }
        map<char, int> mp, mp1;
        for(auto e : s){
            mp[e]++;
        }
        mp1=mp;

        int lastValid=-1;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(nextBig(target[i], mp) != '#'){
                lastValid=i;
            }
            if(mp[target[i]]){
                mp[target[i]]--;
            }
            else{
                break;
            }
        }
        string ans="";
        for(int i=0; i<lastValid; i++){
            ans += target[i];
            mp1[target[i]]--;
        }
        ans += nextBig(target[lastValid], mp1);
        mp1[nextBig(target[lastValid], mp1)]--;
        for(auto [k, f] : mp1){
            for(int j=0; j<f; j++){
                ans += k;
            }
        }
        return ans;
    }
};
