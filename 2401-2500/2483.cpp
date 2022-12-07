class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> nPenalty(customers.size() + 1, 0);
        int yPenalty = 0; 
        for(int i = 0; i < customers.size(); ++i){
            nPenalty[i+1] = nPenalty[i];
            if(customers[i] == 'N') nPenalty[i+1]++;
        }
        int mn = nPenalty.back(), ans = customers.size();
        for(int i = customers.size()-1;  i >= 0; --i){
            if(customers[i] == 'Y') yPenalty++;
            if(mn >= nPenalty[i] + yPenalty){
                ans = i;
                mn = nPenalty[i] + yPenalty;
            }
        }
        return ans;
    }
};
