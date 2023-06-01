class Solution {
public:
      long long minimumCost(string s) {
    long long ans = 0, i = 1, j = s.size()-2;
    while(i < j){
        if(s[i] != s[i-1]) ans += i; 
        if(s[j] != s[j+1]) ans += s.size() - j - 1; 
        i++; j--;
    }
    if(i != j && s[i-1] != s[j+1]) ans += i;
    if(i == j && s[i] != s[i-1]) ans += i;
    if(i == j && s[j] != s[j+1]) ans += s.size() - j - 1;
    return ans;
}
        
    
};
