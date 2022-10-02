class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int> v(32, 0);
        int counter = 0;
        
        int x = num2;
        int y = num1;
        for (int i = 0; i<32; i++)
        {
            if ((x>>i)&1)
            {
                counter++; // counting bits in num2
            }
            if ((y>>i)&1)
            {
                v[i] = 1; // storing binary conversion of num1
            }
        }
        
        vector<int> res(32, 0);
        for (int i = 31; i>=0; i--)
        {
            if (v[i] == 1 && counter > 0)
            {
                res[i] = 1; // To get minimum
                counter--;
            }
        }
        
        if (counter > 0)
        {
            for (int i = 0; i<32; i++)
            {
                if (counter == 0)
                    break;
                if (res[i] == 0)
                {
                    res[i] = 1;
                    counter--;
                }
            }
        }
        int answer = 0;
        
        for (int i = 0; i<32; i++)
        {
            if (res[i])
            {
                answer += pow(2, i);
            }
        }
        return answer;
    }
};
