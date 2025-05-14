class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>vowels(26,0);
        vector<int>conso(26,0);

        auto isVowel=[&](char &ch){
            return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
        };

        for(char &ch:s){
            if(isVowel(ch)) vowels[ch-'a']++;
            else conso[ch-'a']++;
        }

        int vowelMax=0,consoMax=0;
        for(int i=0;i<26;i++){
            vowelMax=max(vowelMax,vowels[i]);
            consoMax=max(consoMax,conso[i]);
        }
        return vowelMax+consoMax;
    }
};
