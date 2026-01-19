class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        long long mod = 1e9 + 7;
        int siz = nums.size();
        
        // conTg1[x] = count of prefix XORs 'x' that just completed target1
        // conTg2[x] = count of prefix XORs 'x' that just completed target2
        unordered_map<int, long long> conTg1; 
        unordered_map<int, long long> conTg2; 
        
        long long curPrf = 0;
        long long dn1 = 0; // Ways ending in target1
        long long dn2 = 0; // Ways ending in target2
        
        // Base case: to start target1, we imagine target2 was "just completed" at index -1
        conTg2[0] = 1; 

        for (int k = 0; k < siz; ++k) {
            curPrf ^= nums[k];
            
            // Current subarray ends target1? Look for prefix ending in target2
            int preXort1 = curPrf ^ target1;
            dn1 = conTg2.count(preXort1) ? conTg2[preXort1] : 0;
            
            // Current subarray ends target2? Look for prefix ending in target1
            int preXort2 = curPrf ^ target2;
            dn2 = conTg1.count(preXort2) ? conTg1[preXort2] : 0;
            
            // Update maps with the new counts for the current prefix XOR
            conTg1[curPrf] = (conTg1[curPrf] + dn1) % mod;
            conTg2[curPrf] = (conTg2[curPrf] + dn2) % mod;
        }
        
        // Total ways is the sum of sequences ending in either target
        return (dn1 + dn2) % mod;
    }
};
