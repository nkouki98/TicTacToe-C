#include <stdio.h>
#include <stdbool.h>

#define computerAi   2
#define player       1
#define tie          0

void displayBoard(int grid[10]);
int checkBoard(int grid[10]);
int playerInput(int grid[10]);
int computerMove(int grid[10]);
int max(int x, int y);
int min(int x, int y);
int minimax(int grid[10], int depth, int alpha, int beta, bool isMax);


void main(){

   //int grid[10] ={' ' , 'X', 'O', 'X', 'O', 'X', 'O', ' ', ' ', ' '};
   int grid[10] ={' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
   int playerI, computerInput;
   printf("\nComputer is X, you are O.\n");
   displayBoard(grid);
   while(1){
      
      switch(checkBoard(grid)){
      case computerAi:
         printf("Computer won!\n");
         return;
      case player:
         printf("You beat the computer!\n");
         return;
      case tie:
         printf("Game tied!\n");
         return; 
      }
      printf("PLAYER INPUT: \n");
      playerI = playerInput(grid);
      for(int i=1;i<10;i++){    
        if(i == playerI){
         grid[i] = 'O';
        }           
      }
      
      displayBoard(grid);

      switch(checkBoard(grid)){
      case 2:
         printf("Computer won!\n");
         return;
      case 1:
         printf("You beat the computer!\n");
         return;
      case 0:
         printf("Game tied!\n");
         return;
      }

      computerInput = computerMove(grid);
      printf("COMP INPUT %d\n", computerInput);
      for(int i=1;i<10;i++){   
         if(i == computerInput){
            grid[i] = 'X';
         }
      }
      displayBoard(grid);
   }
}


int computerMove(int grid[10]){
   
   int bestscore = -1000;
   int move, score;
   for(int i=1;i<10;i++){ 
      if(grid[i] == ' '){
         grid[i] = 'X';
         score = minimax(grid, 0, -1000, 1000, false);
         grid[i] = ' ';
         if(score > bestscore){
            bestscore = score;
            move = i;
         }
      }
   }  
   return move;
}
         

int minimax(int grid[10], int depth, int alpha, int beta, bool isMax){

   int result = checkBoard(grid);
   if(result == computerAi){
      return 10 - depth;
   } else if(result == player){
      return -10 + depth;
   }else if(result == tie){
      return 0;
   } 
   
   if(isMax){
      int bestscore = -1000;     
      for(int i=1;i<10;i++){
         if(grid[i] == ' '){
            grid[i] = 'X';
            int score = minimax(grid, depth + 1, alpha, beta, false);
            grid[i] = ' ';
            bestscore = max(score, bestscore);
            alpha = max(alpha, score);
            if(beta <= alpha){
               break;
            }

         }       
      }
      return bestscore;

   } else {
      int bestscore = 1000; 
      for(int i=1;i<10;i++){
         if(grid[i] == ' '){
            grid[i] = 'O';
            int score = minimax(grid, depth + 1, alpha, beta, true);
            grid[i] = ' ';
            bestscore = min(score, bestscore);
            beta = min(beta, score);
            if(beta <= alpha){
               break;
            }
         }
      }
      return bestscore;
   } 
}


int playerInput(int grid[10]){    
   int x;
   scanf("%d", &x);
   if(grid[x] == ' '){
      return x;
   } else { 
      printf("Invalid!, try again.\n");
      playerInput(grid);}
}


int checkBoard(int grid[10])
{
   //Horizontal 
   if(grid[1] == grid[2] && grid[2] == grid[3] && grid[1]=='X')      {return computerAi;}
   else if(grid[4] == grid[5] && grid[5] == grid[6] && grid[4]=='X') {return computerAi;}
   else if(grid[7] == grid[8] && grid[8] == grid[9] && grid[7]=='X') {return computerAi;}  
   else if(grid[1] == grid[2] && grid[2] == grid[3] && grid[1]=='O') {return player;}
   else if(grid[4] == grid[5] && grid[5] == grid[6] && grid[4]=='O') {return player;}
   else if(grid[7] == grid[8] && grid[8] == grid[9] && grid[7]=='O') {return player;}
   //Vertical
   else if(grid[1] == grid[4] && grid[4] == grid[7] && grid[1]=='X') {return computerAi;}
   else if(grid[2] == grid[5] && grid[5] == grid[8] && grid[2]=='X') {return computerAi;}
   else if(grid[3] == grid[6] && grid[6] == grid[9] && grid[3]=='X') {return computerAi;}
   else if(grid[1] == grid[4] && grid[4] == grid[7] && grid[1]=='O') {return player;} 
   else if(grid[2] == grid[5] && grid[5] == grid[8] && grid[2]=='O') {return player;}
   else if(grid[3] == grid[6] && grid[6] == grid[9] && grid[3]=='O') {return player;}
   //Diagonals
   else if(grid[1] == grid[5] && grid[5] == grid[9] && grid[1]=='X') {return computerAi;}
   else if(grid[3] == grid[5] && grid[5] == grid[7] && grid[3]=='X') {return computerAi;}
   else if(grid[1] == grid[5] && grid[5] == grid[9] && grid[1]=='O') {return player;}
   else if(grid[3] == grid[5] && grid[5] == grid[7] && grid[3]=='O') {return player;}
   //game tie check
   else if(grid[1] != ' ' && grid[2] != ' ' && grid[3] != ' ' &&
       grid[4] != ' ' && grid[5] != ' ' && grid[6] != ' ' && 
       grid[7] != ' ' && grid[8] != ' ' && grid[9] != ' ')           {return tie;}
}


void displayBoard(int grid[10]){

   printf("\n\n\tTic Tac Toe\n\n");
   printf("      |     |     \n");
   printf("  %c   |  %c  |  %c   \n", grid[1], grid[2], grid[3]);
   printf("______|_____|_____\n");
   printf("      |     |     \n");
   printf("  %c   |  %c  |  %c   \n", grid[4], grid[5], grid[6]);
   printf("______|_____|_____\n");
   printf("      |     |     \n"); 
   printf("  %c   |  %c  |  %c   \n", grid[7], grid[8], grid[9]);
   printf("      |     |     \n\n");
   
}

//Function to find minimum of x and y
int min(int x, int y){ 
return y ^ ((x ^ y) & -(x < y)); 
} 
//Function to find maximum of x and y
int max(int x, int y){ 
return x ^ ((x ^ y) & -(x < y));  
}