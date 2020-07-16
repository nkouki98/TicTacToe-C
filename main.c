
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void displayBoard(int grid[3][3]);
void displayInput(int grid[3][3]);
int checkforWin(int grid[3][3]);
int playerInput();
int computerInput(int low, int high);
int runGame();



int main(){
   
   runGame();
   return 0;
}


int runGame(){

   
   int grid[3][3] = {'1','2','3','4','5','6','7','8','9'};
   int i,j,c, win;
   int counter=1;
   char player;

   displayBoard(grid);
   while(1){

   
   printf("PLAYER INPUT: ");
   player = playerInput();
   
   
   for(i=0;i<3;i++)
   {    
      for(j=0;j<3;j++)
      {
        if(grid[i][j] == player)
        grid[i][j] = 'O';
        //printf("grid[%d][%d] = %d\n", i,j, grid[i][j]); 
      }
   }

   displayBoard(grid);
   win = checkforWin(grid);
   
   if (win == 1)
      break;


   
   char computer = computerInput(0,8);   
   printf("COMP INPUT %c", computer);
   for(i=0;i<3;i++)
   {    
      for(j=0;j<3;j++)
      {
        if(grid[i][j] == computer)
        grid[i][j] = 'X';
        //printf("grid[%d][%d] = %d\n", i,j, grid[i][j]); 
      }
   }
   
   displayBoard(grid);
   win = checkforWin(grid);
   
   if (win == 1)
      break;
   
   }

   printf( "win %d\n", win ); 
   
  
  
  
 

  
   return 0;

    
    
}



int computerInput(int low, int high){
 

  
   int num;
   
   int range[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   num = (rand() % (high - low + 1)) + low;
   return range[num];
}
   //printf("from array %c", range[num]);
   


int playerInput(){
    
   char x;
  // printf("Enter number: ");
   scanf("%c%*c", &x);
   //printf("Number is %c \n", x);
   return x;

}



int checkforWin(int grid[3][3]){


   //Horizontal 
   if (grid[0][0] == grid[0][1] && grid[0][2] == grid[0][0])
      return 1;
   else if(grid[1][0] == grid[1][1] && grid[1][2] == grid[1][0])
      return 1;
   else if(grid[2][0] == grid[2][1] && grid[2][2] == grid[2][0])
      return 1;



   //Vertical
   else if (grid[0][0] == grid[1][0] && grid[2][0] == grid[0][0])
      return 1;
   else if(grid[0][1] == grid[1][1] && grid[2][1] == grid[0][1])
      return 1;
   else if(grid[0][2] == grid[1][2] && grid[2][2] == grid[0][2])
      return 1;


   //Diagonals
   else if (grid[0][0] == grid[1][1] && grid[2][2] == grid[0][0])
      return 1;
   else if(grid[0][2] == grid[1][1] && grid[2][0] == grid[0][2])
      return 1;
   
   else 
      return 0;


}




void displayBoard(int grid[3][3]){


   printf("\n\n\tTic Tac Toe\n\n");
   printf("     |     |     \n");
   printf(" %c   |  %c  |  %c   \n", grid[0][0], grid[0][1], grid[0][2]);
   printf("_____|_____|_____\n");
   printf("     |     |     \n");
   printf(" %c   |  %c  |  %c   \n", grid[1][0], grid[1][1], grid[1][2]);
   printf("_____|_____|_____\n");
   printf("     |     |     \n"); 
   printf(" %c   |  %c  |  %c   \n", grid[2][0], grid[2][1], grid[2][2]);
   printf("     |     |     \n\n");


}
