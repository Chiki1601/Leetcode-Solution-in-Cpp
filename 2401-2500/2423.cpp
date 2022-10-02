class Solution {
public:
    bool equalFrequency(string word) {
          for(int i = 0; i < word.size(); i++) {
              vector<int> fre(26,0);
              
              for(int j = 0; j < word.size(); j++) {
                  if(j == i) continue;
                  fre[word[j] - 'a']++;
              }
              
              int freq = -1;
              
              for(int j = 0; j < 26; j++) {
                  if(fre[j] > 0) {freq = fre[j]; break;}
              }
              
              bool flag = true;
              for(int j = 0; j < 26; j++) {
                  if(fre[j] > 0 && fre[j] != freq) flag = false;
              }
              
              if(flag) return true;
          }
        return false;
    }
};
