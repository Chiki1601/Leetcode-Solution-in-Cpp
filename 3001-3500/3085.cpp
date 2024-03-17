class Solution {
public:
  int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);
    int deleted = 0, ans = word.size();
    for(auto c: word) freq[c-'a']++;             // find frequency of each chars
    sort(freq.begin(), freq.end());              // sort the freq array
    for(int i = 0; i < freq.size(); ++i){        // Iterate over freq 
        int res = deleted, minFreq = freq[i];    // consider the current freq as the min freq after deletion. Also add the already deleted freq to temporary result
        for(int j = freq.size()-1; j > i; --j){  // iterate over freq array to evaluate the chars to be deleted from the higher freq side of the freq array
            if(freq[j] - minFreq <= k) break;    // Once condition is satisfied then exit from the loop
            res += freq[j] - minFreq - k;        // accumulate on the result - number of items to be deleted
        }
        ans = min(ans, res);                     // keep tracking the min possible value
        deleted += freq[i];                      // update the deleted freq with current freq
    }
    return ans;
}
};
