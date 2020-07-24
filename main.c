
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <math.h>

void displayBoard(int grid[10]);
int checkforWin(int grid[10]);
int playerInput(int grid[10]);
int runGame();
bool boardEmpty(int grid[10]);
int max(int x, int y);
int min(int x, int y);
int minimax(int grid[10], int depth, bool isMax);
int computerMove(int grid[10]);


int main(){
   runGame();
   return 0;
}


int runGame(){

   
   // int grid[10] ={'s' , 'X', 'O', 'X', 'O', 'O', 'X', ' ', ' ', ' '};
   int grid[10] ={'s' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
   int i,j,c,win, temp;
   int player, computer;
   bool b;

   while(1)
   {
      
      displayBoard(grid);
  
      b = boardEmpty(grid);
      printf("Your turn! b=%d\n", b);

      if(temp = checkforWin(grid)==1)
      {
         printf("You beat the computer!\n");
         break;
      }
      else if(temp = checkforWin(grid)==2)
      {
         printf("Computer won!\n");
         break;
      }
      else if(b==1)
      {
         printf("PLAYER INPUT: \n");
         player = playerInput(grid);
         for(i=1;i<10;i++){    
            if(i == player){
               grid[i] = 'O';
            }            
         }
         displayBoard(grid);
      }
      else{ 
         printf("Game tied!\n");
         break;
      }
         
           
      b = boardEmpty(grid);
      printf("Computer's turn b=%d\n", b);
      

      if(temp = checkforWin(grid)==1)
      {
         printf("You beat the computer!\n");
         break;
      }
      else if(temp = checkforWin(grid)==2)
      {
         printf("Computer won!\n");
         break;
      }
      else if(b==1)
      {
         computer = computerMove(grid);
         printf("COMP INPUT %d\n", computer);
         for(i=1;i<10;i++){   
            if(i == computer){
               grid[i] = 'X';
            }
         }
         displayBoard(grid);
      }
      else
      {  
         printf("Game tied!\n");
         break;
      }
         
   }
      win = checkforWin(grid);
      printf("win %d\n", win); 
      b = boardEmpty(grid);
      printf("this b=%d\n", b);
   
      return 0;
   
}


int computerMove(int grid[10]){
   int bestscore = -1000;
   int move, score;

   for(int i=1;i<10;i++)
   {
      if(grid[i] == ' ')
      {
         grid[i] = 'X';
         score = minimax(grid, 0, false);
         grid[i] = ' ';
         if(score > bestscore)
         {
            bestscore = score;
            move = i;
         }
      }
   }  
   return move;
}

         

int minimax(int grid[10], int depth, bool isMax)
{

   int result = checkforWin(grid);

   if(result==2) {return 10 - depth;}
  
   else if(result==1) {return -10 + depth;}
  
   else if(boardEmpty(grid)==0) {return 0;} 
   
   else if(isMax==1)
   {
      int bestscore = -1000;     
      for(int i=1;i<10;i++)
      {
         if(grid[i] == ' ')
         {
            grid[i] = 'X';
            int score = minimax(grid, depth+1, false);
            grid[i] = ' ';
            bestscore = max(score, bestscore);
         }
         
      }
      return bestscore;
   } 
   else 
   {
      int bestscore = 1000; 
      for(int i=1;i<10;i++)
      {
         if(grid[i] == ' ')
         {
            grid[i] = 'O';
            int score = minimax(grid, depth+1, true);
            grid[i] = ' ';
            bestscore = min(score, bestscore);
         }
      }
      return bestscore;
   }
     
}


int playerInput(int grid[10])
{    
   int x;
   scanf("%d", &x);
   if(grid[x] == ' ') {return x;}

   else { printf("Invalid!, try again.\n");
         playerInput(grid);}

   
   
}


bool boardEmpty(int grid[10])
{   
   int i;
   if (grid[1] != ' ' && grid[2] != ' ' && grid[3] != ' ' &&
       grid[4] != ' ' && grid[5] != ' ' && grid[6] != ' ' && 
       grid[7] != ' ' && grid[8] != ' ' && grid[9] != ' ') {return 0;}
   else {return 1;}
}  
      


int checkforWin(int grid[10])
{

   //Horizontal 
   if(grid[1] == grid[2] && grid[2] == grid[3] && grid[1]=='X')      {return 2;}
   else if(grid[4] == grid[5] && grid[5] == grid[6] && grid[4]=='X') {return 2;}
   else if(grid[7] == grid[8] && grid[8] == grid[9] && grid[7]=='X') {return 2;}
   
   else if(grid[1] == grid[2] && grid[2] == grid[3] && grid[1]=='O') {return 1;}
   else if(grid[4] == grid[5] && grid[5] == grid[6] && grid[4]=='O') {return 1;}
   else if(grid[7] == grid[8] && grid[8] == grid[9] && grid[7]=='O') {return 1;}

   //Vertical
   else if(grid[1] == grid[4] && grid[4] == grid[7] && grid[1]=='X') {return 2;}
   else if(grid[2] == grid[5] && grid[5] == grid[8] && grid[2]=='X') {return 2;}
   else if(grid[3] == grid[6] && grid[6] == grid[9] && grid[3]=='X') {return 2;}
   
   else if(grid[1] == grid[4] && grid[4] == grid[7] && grid[1]=='O') {return 1;} 
   else if(grid[2] == grid[5] && grid[5] == grid[8] && grid[2]=='O') {return 1;}
   else if(grid[3] == grid[6] && grid[6] == grid[9] && grid[3]=='O') {return 1;}


   //Diagonals
   else if(grid[1] == grid[5] && grid[5] == grid[9] && grid[1]=='X') {return 2;}
   else if(grid[3] == grid[5] && grid[5] == grid[7] && grid[3]=='X') {return 2;}


   else if(grid[1] == grid[5] && grid[5] == grid[9] && grid[1]=='O') {return 1;}
   else if(grid[3] == grid[5] && grid[5] == grid[7] && grid[3]=='O') {return 1;}
   
   else {return 0;}

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

//Function to find minimum of x and y
int min(int x, int y) 
{ 
return y ^ ((x ^ y) & -(x < y)); 
} 
  
//Function to find maximum of x and y
int max(int x, int y) 
{ 
return x ^ ((x ^ y) & -(x < y));  
}