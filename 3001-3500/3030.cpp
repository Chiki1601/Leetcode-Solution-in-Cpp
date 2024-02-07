
using ll=long long;
   int row, col;
    vector<vector<int>> sums;
// This function calculating sum of submatrix from (0,0)->(i,j) or u can say it calculating the sum of rectagle((0,0),(i,j)) and storing at sum[i+1][j+1].
    void solve1(vector<vector<int>> &matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] + 
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }
// This function will give the sum of submaxtrix or rectangle formed by coordinate (row1,col1) and (row2,col2).
    int solve2(int row1, int col1, int row2, int col2) 
    {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }


class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& a, int tar) {
        row=a.size();
        col=a[0].size();
        solve1(a);
        ll n=row;
        ll m=col;
      vector<vector<ll>>  b(row,vector<ll>(col,-1));
// here i am calculating sum of all possible 3*3 submatrix and storing in b[i][j]..
  // where b[i][j] denotes the sum of 3*3 submatrix or rectangle whose starting coordinates are (i,j) andending coordinates (i+2,j+2)..
         for(int i=0;i<row-2;i++)
        {
           for(int j=0;j<col-2;j++)
            {
                b[i][j]=solve2(i,j,i+2,j+2);
            }
        }
// total no of 3*3 submatrix poosible= (n-2)*(m-2)..
// here des vector of size((n-2)*(m-3)) will be  storing boolean value where 0 detones -->not a region and 1 denotes--> a region..
// where des[i,j] is denoting the submatrix or rectangle whose starting coordiantes (i,j) and ending coordinates (i+2,j+2) is a region or not..
        
// now lets see how decision is taken that a particular submatrix is region or not..
       vector<vector<ll>>des(row-2,vector<ll>(col-2,1));
         vector<vector<int>>ans(row,vector<int>(col));
         for(int i=0;i<row;i++)
        {
             // here i am moving from left to right
           for(int j=0;j<col;j++)
            {
            // here i am moving from up to down
      // every point(i,j) in 2-D matrix can have 2 to 4 neighbours..
      // since we are moving from left to right and up to down so, we have take care of only two neighbours(down ,right) that is down(i+1,j) & right(i,j+1)..
                
                // here i am checking the right neighbour (i,j+1)
                // if abs((i,j)-(i,j+1)>threshhold) means if abs diff b/w its curr points(pixel) and its right neighbour(pixel) is greater than threshold then all those submatrix  that contains both these points(Pixels) will not be region..
                if(j+1<m && abs(a[i][j]-a[i][j+1])>tar)
                {
                    // now i am checking the points ((i,j) & (i,j+1)) together can lie in how many submatrix 
                    // these point can lie into min=1 and max=6 submatrixes...
  /*                  1 2 3 4 5 
                   1 | | | | | |   lets consider a scenario of(5*5) matrix now i am at point p(3,3) denoted by (*) and its right             
                   2 | | | | | |   neighbour denoted by (#) at q(3,4)..
                   3 | | |*|#| |   now i can make 6 submatrix containing point (p,q)  
                   4 | | | | | |   now i will writing starting coordinates of 6 (3*3)submatrix..
                   5 | | | | | |   1)->(1,3)
                                   2)->(2,3)
                                   3)->(3,3)
                                   4)->(1,2)
                                   5)->(2,2)
                                   6)->(3,2)
                          it is clear from here that a point p and q affect these 6 (3*3) submatrix..   */
                          for(int i1=max(0,i-2);i1<=i;i1++)
                        {
                            for(int j1=max(0,j-1);j1<=j;j1++)
                           {
                                // here (i1,j1) denotes submatrix containing  (i,j) & (i,j+1) points
                                // here if condition is checking that coordinates with starting point(i1,j1) can make a substring of(3*3) or not..
                                if(i1+2<row && j1+2<col)
                                {
    // here we come to conclusion that submatrix with starting coordinates(i1,j1) and ending cordinates(i1+2,j1+2) contains points (i,j)&(i,j+1) whose abs diff is greater than threshhold so particular submatrix can't be a region. so do bitwise and(&) with 0 to make it not a region.. 
                                   des[i1][j1]=des[i1][j1]&0; 
                                }
                           }
                        }
                   
                }
                
                // similarly here i am checking the Down neighbour(Pixel) (i+1,j)
                if(i+1<n && abs(a[i][j]-a[i+1][j])>tar)
                {
                     for(int i1=max(0,i-1);i1<=i;i1++)
                        {
                            for(int j1=max(0,j-2);j1<=j;j1++)
                           {
                                if(i1+2<row && j1+2<col)
                                {
                                   des[i1][j1]=des[i1][j1]&0; 
                                }
                           }
                        }
                   
                }
            }    
        }
    /*     Note --> every point can lie in minimum one(1)-> (3*3)submatrix and maximum nine(9)-> (3*3)submatrix..
                      1 2 3 4 5 
                   1 | | | | | |   lets consider a scenario of(5*5) matrix now i am at point p(3,3) denoted by (*) and its right             
                   2 | | | | | | 
                   3 | | |*| | |   now i can make 9 submatrix containing (p,q)  
                   4 | | | | | |   now i will writing starting coordinates of 9 (3*3)submatrix..
                   5 | | | | | |   
                                   1)-> (1,1)      4)->(1,2)    5)->(1,3)
                                   2)-> (2,1)      5)->(2,2)    6)->(2,3)
                                   3)-> (3,1)      6)->(3,2)    7)->(3,3)
               basically every point lie in submatrix with starting coordinates (i1,j1) where i1 and j1 are given below :-
                                          (i1>=(i-2) && i1<=i)  , (j1>=(j-2)  && j1<=j)      
                                          */
          for(int i=0;i<row;i++)
         {
           for(int j=0;j<col;j++)
            {
                ll ans1=0,c=0;
                
     //           here we are checking all possible 1 to 9 submatrix which are a region and containg point (i,j)...
                // c is keeping track of out of all possible submatrix containing point (i,j) is a region
                         for(int i1=max(0,i-2);i1<=i;i1++)
                        {
                            for(int j1=max(0,j-2);j1<=j;j1++)
                           {
                                // here we  are checking a submatrix with starting coordinates (i1,j1) are region or not..
                                   if(b[i1][j1]!=-1 && des[i1][j1]==1) 
                                   {
                                       c++;
                                       // we are taking avearage of submatrix(i1,j1)...
                                       ans1+=(b[i1][j1]/9);
                            
                                   }
                                
                           }
                         }
                if(c==0)
                {
                    ans[i][j]=a[i][j];
                }
                else
                {
                ans[i][j]=ans1/c;
                }
            }
             
        }

        
        return ans;
    }
};
