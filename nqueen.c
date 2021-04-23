#include <stdio.h>
//Number of queens
int N;
//chessboard
int board[100][100];
//function to check if the cell is attacked or not
int is_attack(int i,int j)
{
  int k,l;
  //checking if there is a queen in row or column
  for(k=0;k<N;k++)
  {
    if((board[i][k] == 1) || (board[k][j] == 1))
      return 1;
  }
  //checking for diagonals
  for(k=0;k<N;k++)
  {
      for(l=0;l<N;l++)
      {
          if(((k+l) == (i+j)) || ((k-l) == (i-j)))
          {
              if(board[k][l] == 1)
                  return 1;
          }
      }
  }
  return 0;
}

int N_queen(int n)
{
  int i,j;
  if(n==0)
      return 1;
  for(i=0;i<N;i++)
  {
      for(j=0;j<N;j++)
      {
          if((!is_attack(i,j)) && (board[i][j]!=1))
          {
              board[i][j] = 1;
                //wether we can put the next queen with this arrangment or not
              if(N_queen(n-1)==1)
              {
                  return 1;
              }
              board[i][j] = 0;
          }
      }
  }
  return 0;
}

int main()
{
  printf("Enter the value of N for NxN chessboard\n");
  scanf("%d",&N);
  int arr1[N];
  int i,j;
  for(i=0;i<N;i++)//setting all elements to 0
  {
    for(j=0;j<N;j++)
    {
      board[i][j]=0;
    }
  }
  N_queen(N);
  int e=0;
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
        printf("%d\t",board[i][j]);

    printf("\n");
  }
  printf("\n" );
  printf("THE QUEEN ARE SAFE AT THESE LOCATION\n" );
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      if (board[i][j])
      {
        printf("%d\t",j+1);
      }
    }
  }
  printf("\n" );
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      if (board[j][i])
      {
        printf("%d\t",j+1);
      }
    }
  }
}
