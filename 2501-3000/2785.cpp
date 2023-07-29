class Solution {
public:
    unordered_set<char> vowel{'a', 'e', 'i', 'o','u', 'A', 'E', 'I', 'O','U'};
        
    bool check(char c){
        return (vowel.find(c) != vowel.end());
    }
    
    string sortVowels(string s) {
        map<int, int> mp;
        for(auto c: s) mp[c] += check(c);        //put all vowel in the map with frequency 
        map<int, int>::iterator it = mp.begin(); //set an iterator to the begining of the map
        for(int i = 0; i < s.size(); ++i){
            if(check(s[i])) {                    //check for vowel letter then replace this with sorted vowel
                s[i] = (*it).first;              //from the map get the first key(vowel) which is non zero
                if(--(*it).second ==  0) it++;   //decrease the frequency of the vowel and if zero, then move iterator to next vowel
            }
        }
        return s;
    }
};
