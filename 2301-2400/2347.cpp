class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int a;int b; int c; int d;
        
        if(suits[0]==suits[1] && suits[2]==suits[3] && suits[3]==suits[4]) return "Flush";
        
        sort(ranks.begin(), ranks.end());
        int count = 1;
        int ans = 0;
        int card = ranks[0];
        for(int i=1;i<ranks.size(); i++){
            if(ranks[i]==card){
                count++;
            }else{
                card = ranks[i];
                count = 1;
            }
            ans=  max(ans, count);
        }
        if(ans >= 3)return "Three of a Kind";
        else if(ans == 2) return "Pair";
        else return "High Card";
    }
};
