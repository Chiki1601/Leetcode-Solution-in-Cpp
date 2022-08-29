class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
           int total_time = 0;
           
          // for P
          bool isP = false, isG = false, isM = false;
          for(int i = garbage.size() - 1; i >= 0; i--) {
                  if(isP == false) {
                      for(int j = 0; j < garbage[i].size(); j++) {
                          if(garbage[i][j] == 'P') {isP = true; break;}
                      }
                  }
                if(isP) {
                          for(int j = 0; j <= i; j++) {
                              string s = garbage[j];
                              for(char ch : s) {
                                  if(ch == 'P') total_time++;
                              }
                                if(j > 0) total_time += travel[j-1];
                          }
                    break;                    
                }
          }
              
              // for G
              for(int i = garbage.size() - 1; i >= 0; i--) {
                  if(isG == false) {
                      for(int j = 0; j < garbage[i].size(); j++) {
                          if(garbage[i][j] == 'G') {isG = true; break;}
                      }
                  }
                if(isG) {
                          for(int j = 0; j <= i; j++) {
                              string s = garbage[j];
                              for(char ch : s) {
                                  if(ch == 'G') total_time++;
                              }
                                if(j > 0) total_time += travel[j-1];
                          }
                    break;                    
                }
              }
                  
                  // for M
                  for(int i = garbage.size() - 1; i >= 0; i--) {
                  if(isM == false) {
                      for(int j = 0; j < garbage[i].size(); j++) {
                          if(garbage[i][j] == 'M') {isM = true; break;}
                      }
                  }
                if(isM) {
                          for(int j = 0; j <= i; j++) {
                              string s = garbage[j];
                              for(char ch : s) {
                                  if(ch == 'M') total_time++;
                              }
                                if(j > 0) total_time += travel[j-1];
                          }
                    break;                    
                }
          }
        return total_time;
        
    }
};
