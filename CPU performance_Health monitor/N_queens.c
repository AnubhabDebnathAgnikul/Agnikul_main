#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
__int32_t board[20],count;
 
#define N 8

__int32_t main()
{
    __int32_t n,i,j;
    void queen(__int32_t row,__int32_t n);
    
    //printf(" - N Queens Problem Using Backtracking -");
    // printf("\n\nEnter number of Queens:");
    // scanf("%d",&n);
    queen(1,N);
    return 0;
}
    
//function for printing the solution
void print(__int32_t n)
{
    __int32_t i,j;
    printf("\n\nSolution %d:\n\n",++count);
    
    for(i=1;i<=n;++i)
    printf("\t%d",i);
    
    for(i=1;i<=n;++i)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j) //for nxn board
        {
            if(board[i]==j)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
        }
    }
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
__int32_t place(__int32_t row,__int32_t column)
{
    __int32_t i;
    for(i=1;i<=row-1;++i)
    {
        //checking column and digonal conflicts
        if(board[i]==column)
            return 0;
        else
            if(abs(board[i]-column)==abs(i-row))
                return 0;
    }
    
    return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void queen(__int32_t row,__int32_t n)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
    print(n); //printing the board configuration
   else //try queen with next position
    queen(row+1,n);
  }
}
}