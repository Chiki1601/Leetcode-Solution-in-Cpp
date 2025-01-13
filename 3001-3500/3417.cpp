//Method 1 :  plain brute force
//store all elements in expected L->R then R->L ordered and pick alternate ones in a new vector
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) 
    {
        vector<int> ans;
        bool goingright = true;
        int r =0,c=0;
        while(r<grid.size())
            {
                if(goingright)
                {
                    for(int i = 0 ; i < grid[0].size();i++)
                        {
                            ans.push_back(grid[r][i]);
                        }
                    c = grid[0].size()-1;
                    r++;
                    goingright=false;
                }
                else
                {
                    for(int i = c ; i >=0 ; i--)
                        {
                            ans.push_back(grid[r][i]);
                        }
                    r++;
                    goingright=true;
                }
            }
        vector<int> finalans;
        for(int i =0 ; i< ans.size();i+=2)
                finalans.push_back(ans[i]);
        return finalans;
    }
};

//Method 2 : Optimized Brute force
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) 
    {
        vector<int> result;
        bool goRight = true; // track direction
        
        for (int r = 0; r < grid.size(); r++) 
        {
            if (goRight) 
            {
                for (int c = 0; c < grid[r].size(); c += 2)  // L->R skipping alternate cells
                    result.push_back(grid[r][c]);
            } 
            else 
            {
                int start = grid[r].size() % 2 == 0 ? grid[r].size() - 1 : grid[r].size() - 2; // if row length is even, while going L->R first element is used, last is not used, then in next row it starts from last element
                for (int c = start; c >= 0; c -= 2)  // R->L skipping alternate cells
                    result.push_back(grid[r][c]);
            }
            //while going left to right, it will always have the first element
            //since total element in a pair to left to right and right to left is even
            
            goRight = !goRight; // Toggle direction
        }
        return result;
    }
};

//Method 3 : a bit smarter
class Solution
{
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) 
    {
        vector<int> ans;

        //even indexed row -> even indexed elements
        //odd indexed row -> odd indexed elements
        for(int r = 0 ; r < grid.size();r++)
            {
                if(r%2==0)
                {
                    for(int c = 0 ; c < grid[0].size() ; c++)
                        if(c%2==0) ans.push_back(grid[r][c]); //we can do c+=2 also
                }
                else
                {
                   for(int c = grid[0].size()-1 ; c >=0 ; c--)
                        if(c%2==1) ans.push_back(grid[r][c]); //we could find the start element as method 2 also
                }
            }
        return ans;
    }
};
