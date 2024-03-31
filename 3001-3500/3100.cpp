class Solution {
public:
   int maxBottlesDrunk(int numBottles, int numExchange) {
    int emptyBottles = 0, drinkCount = 0;
    while(numBottles > 0 || emptyBottles >= numExchange){
        if(emptyBottles >= numExchange){
            emptyBottles -= numExchange;
            numExchange++;
            numBottles++;
        }
        drinkCount += numBottles;
        emptyBottles += numBottles;
        numBottles = 0;
    }
    return drinkCount;
}
};
