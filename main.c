
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#include <math.h>

void displayBoard(int grid[10]);
void displayInput(int grid[10]);
int checkforWin(int grid[10]);
int playerInput();
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
      printf("PLAYER BOOL b=%d\n", b);

      if(temp = checkforWin(grid)==1 || checkforWin(grid)==2){
         break;
      }
      else if(b==1)
      {
         printf("PLAYER INPUT: ");
         player = playerInput();
         for(i=1;i<10;i++){    
            if(i == player){
               grid[i] = 'O';
            }            
         }
         displayBoard(grid);
      }
      else{ 
         printf("TIE\n");
         break;
      }
         
           
      b = boardEmpty(grid);
      printf("COMP BOOl b=%d\n", b);
      

      if(temp = checkforWin(grid)==1 || checkforWin(grid)==2 ){
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


int computerMove(int grid[10]){
   int bestscore = -1000;
   int move, score;

   for(int i=1;i<10;i++)
   {
      if(grid[i] == ' ')
      {
         grid[i] = 'X';
         score = minimax(grid, 0, false);
         //printf("bestscore %d\n", bestscore);
         //printf("score %d\n", score);
         grid[i] = ' ';
         if(score > bestscore)
         {
            printf("BESTCORE %d\n", bestscore);
            printf("SCORE %d\n", score);

            bestscore = score;
            move = i;
            printf("MOVE %d\n", move );
         }
      }
   }  
   return move;
}

         

int minimax(int grid[10], int depth, bool isMax)
{


   //displayBoard(grid);

   //printf("ISMAX %d\n", isMax);
   int result = checkforWin(grid);
   //printf("RESULT no if %d\n", result);

   if(result==2){
      //printf("RESULT %d\n", result);
      return 10 - depth;
   }
   else if(result==1){
      //printf("RESULT %d\n", result);
      return -10 + depth;
   }
   else if(boardEmpty(grid)==0)
   {
      return 0;
   } 
   
   else if(isMax==1)
   {
      int bestscore = -1000;
      //printf("ifmax run then %d", bestscore);     
      for(int i=1;i<10;i++)
      {
         if(grid[i] == ' ')
         {
            //printf("grid %d\n", i);
            grid[i] = 'X';
            int score = minimax(grid, depth+1, false);
            //printf("this SCORE %d\n", score);
            grid[i] = ' ';
            bestscore = max(score, bestscore);
         }
         
      }
      return bestscore;
   } 
   else 
   {
      int bestscore = 1000;
      //printf("else run then %d\n", bestscore);   
      for(int i=1;i<10;i++)
      {
         if(grid[i] == ' ')
         {
            //printf(" HUmangrid %d\n", i);
            grid[i] = 'O';
            int score = minimax(grid, depth+1, true);
            //printf("SCORE %d\n", score);
            grid[i] = ' ';
            bestscore = min(score, bestscore);
         }
      }
      return bestscore;
   }
     
}


int playerInput()
{    
   int x;
   //printf("Enter number: ");
   scanf("%d", &x);
   return x;
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

/*Function to find minimum of x and y*/
int min(int x, int y) 
{ 
return y ^ ((x ^ y) & -(x < y)); 
} 
  
/*Function to find maximum of x and y*/
int max(int x, int y) 
{ 
return x ^ ((x ^ y) & -(x < y));  
}