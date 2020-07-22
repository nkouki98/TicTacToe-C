
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <math.h>


void displayBoard(int grid[10]);
void displayInput(int grid[10]);
int checkforWin(int grid[10]);
int playerInput();
int computerInput(int low, int high);
int runGame();
bool boardEmpty(int grid[10]);
int max(int num1, int num2);
int min(int num1, int num2);

int computerMove(int grid[10]);
int minimax(int grid[10]);


int main(){
   
   runGame();
   return 0;
}


int runGame(){

   
   int grid[10] ={'s' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
   int i,j,c,win, temp;
   int player, computer;
   bool b;

   while(1){
      
      displayBoard(grid);
  
      b = boardEmpty(grid);
      printf("PLAYER BOOL b=%d\n", b);



      if((temp=checkforWin(grid))==1)
         break;
      else if(b==1){
         printf("PLAYER INPUT: ");
         player = playerInput();
         for(i=1;i<10;i++){    
            if(i == player)
               grid[i] = 'O';
            
         }
         displayBoard(grid);
      }
      else{ 
         printf("TIE\n");
         break;
      }
         
      //win = checkforWin(grid);
     // if (win == 1)
       //  break;

     
      
      b = boardEmpty(grid);
      printf("COMP BOOl b=%d\n", b);
      

      if((temp=checkforWin(grid))==1)
         break;
      else if(b==1){
         computer =computerInput(1,10);
         printf("COMP INPUT %d\n", computer);
         for(i=1;i<10;i++){   
            if(i == computer)
               grid[i] = 'X';
         }
         displayBoard(grid);
      }
      else{  
         printf("TIE\n");
         break;
      }
     
         
      }
      win = checkforWin(grid);
      printf("win %d\n", win); 
      b = boardEmpty(grid);
      printf("this b=%d\n", b);
   
      return 0;

      
    
}


         



int computerInput(int low, int high){
 
   int num;   
   num = (rand() % (high - low + 1)) + low;
   return num;

}

  
   


int playerInput(){
    
   int x;
  // printf("Enter number: ");
   scanf("%d", &x);
   return x;

}



bool boardEmpty(int grid[10]){
   
  
   int i;
   if (grid[1] != ' ' && grid[2] != ' ' && grid[3] != ' ' &&
       grid[4] != ' ' && grid[5] != ' ' && grid[6] != ' ' && grid[7] 
       != ' ' && grid[8] != ' ' && grid[9] != ' ')
      return 0;
   else
      return 1;
   
   
      
    
   
  
}

int checkforWin(int grid[10]){


   //Horizontal 
   if (grid[1] == grid[2] && grid[2] == grid[3] && grid[1]=='X')
      return 1;
   else if(grid[4] == grid[5] && grid[5] == grid[6] && grid[4]=='X')
      return 1;
   else if(grid[7] == grid[8] && grid[8] == grid[9] && grid[5]=='X')
      return 1;

   else if (grid[1] == grid[2] && grid[2] == grid[3] && grid[1]=='O')
      return 1;
   else if(grid[4] == grid[5] && grid[5] == grid[6] && grid[4]=='O')
      return 1;
   else if(grid[7] == grid[8] && grid[8] == grid[9] && grid[7]=='O')
      return 1;


   //Vertical
   else if (grid[1] == grid[4] && grid[4] == grid[7] && grid[1]=='X')
      return 1;
   else if(grid[2] == grid[5] && grid[5] == grid[8] && grid[2]=='X')
      return 1;
   else if(grid[3] == grid[6] && grid[6] == grid[9] && grid[3]=='X')
      return 1;
   else if (grid[1] == grid[4] && grid[4] == grid[7] && grid[1]=='O')
      return 1;
   else if(grid[2] == grid[5] && grid[5] == grid[8] && grid[2]=='O')
      return 1;
   else if(grid[3] == grid[6] && grid[6] == grid[9] && grid[3]=='O')
      return 1;



   //Diagonals
   else if (grid[1] == grid[5] && grid[5] == grid[9] && grid[1]=='X')
      return 1;
   else if(grid[3] == grid[5] && grid[5] == grid[7] && grid[3]=='X')
      return 1;
   else if (grid[1] == grid[5] && grid[5] == grid[9] && grid[1]=='O')
      return 1;
   else if(grid[3] == grid[5] && grid[5] == grid[7] && grid[3]=='O')
      return 1;
   else 
      return 0;


}




void displayBoard(int grid[10]){


   printf("\n\n\tTic Tac Toe\n\n");
   printf("     |     |     \n");
   printf(" %c   |  %c  |  %c   \n", grid[1], grid[2], grid[3]);
   printf("_____|_____|_____\n");
   printf("     |     |     \n");
   printf(" %c   |  %c  |  %c   \n", grid[4], grid[5], grid[6]);
   printf("_____|_____|_____\n");
   printf("     |     |     \n"); 
   printf(" %c   |  %c  |  %c   \n", grid[7], grid[8], grid[9]);
   printf("     |     |     \n\n");


}


int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}


int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}