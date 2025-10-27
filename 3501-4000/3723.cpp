class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return ""; // cheching if sum exceeds the maximum digit sum
        int noOf9 = sum/9; // by cheching some testcase it is found that, add at most 9 as possible in the begining of string so that square sum is maximised.
        int r= sum%9; //finding the remaining digit
        string s = "";
        s.append(noOf9, '9'); //appending '9' ate the begining
        if(s.size() < num) s += char(48+r); //appending remaining digit

        while(s.size() < num) { //appending '0' to make length equal to num
            s += '0';
        }
        return s;
    }
};
