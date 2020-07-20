
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>


void displayBoard(int grid[10]);
void displayInput(int grid[10]);
int checkforWin(int grid[10]);
int playerInput();
int computerInput(int low, int high);
int runGame();
bool boardEmpty(int grid[10]);


int main(){
   
   runGame();
   return 0;
}


int runGame(){

   
   int grid[10] ={'s' , '1', 'X', 'X', 'X', 'O', 'O', 'X', 'O', 'X'};
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
         computer = computerInput(1,10);   
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

   if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
        grid[4] != '4' && grid[5] != '5' && grid[6] != '6' && grid[7] 
        != '7' && grid[8] != '8' && grid[9] != '9')
        return 0;
   else
      return 1;
   
   
      
    
   
  
}

int checkforWin(int grid[10]){


   //Horizontal 
   if (grid[1] == grid[2] && grid[2] == grid[3])
      return 1;
   else if(grid[4] == grid[5] && grid[5] == grid[6])
      return 1;
   else if(grid[7] == grid[8] && grid[8] == grid[9])
      return 1;



   //Vertical
   else if (grid[1] == grid[4] && grid[4] == grid[7])
      return 1;
   else if(grid[2] == grid[5] && grid[5] == grid[8])
      return 1;
   else if(grid[3] == grid[6] && grid[6] == grid[9])
      return 1;


   //Diagonals
   else if (grid[1] == grid[5] && grid[5] == grid[9])
      return 1;
   else if(grid[3] == grid[5] && grid[5] == grid[7])
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
