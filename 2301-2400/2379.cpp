class Solution {
public:
    int minimumRecolors(string blocks, int k) {
              int ans = INT_MAX;
              int n = blocks.size();
              for(int i = 0; i < n; i++) {
                  for(int j = i; j < n; j++) {
                          if(j - i + 1 == k) {
                              int w = 0;
                              for(int k = i; k <= j; k++) {
                                  if(blocks[k] == 'W') {
                                      w++;
                                  }
                              }   
                              ans = min(ans, w);
                          }
                  }
              }
        
        return ans;
    }
};
