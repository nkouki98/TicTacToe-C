
#include <stdio.h>
#include <stdlib.h>



void displayBoard(int grid[3][3]);
void displayInput(int grid[3][3]);

int userInput();


int main(){

   
   int grid[3][3] = {'1','2','3','4','5','6','7','8','9'};
   int i,j,c;
   char str[10];
   int counter=1;
   char num;
   
   //for(i=0;i<3;i++)
   //{    
     //  for(j=0;j<3;j++){
       //    grid[i][j] = counter;
         //  printf("grid[%d][%d] = %d\n", i,j, grid[i][j] );   
           //counter++;
       //}
   //}

   while(1){

   
   displayBoard(grid);
   num = userInput();
   
   printf("char is %c\n", num);
   printf("%c\n", num);
 
    for(i=0;i<3;i++)
   {    
      for(j=0;j<3;j++){
        if(grid[i][j] == num)
        grid[i][j] = 'X';
        printf("grid[%d][%d] = %d\n", i,j, grid[i][j] ); 
      }
   }


   displayBoard(grid);
   }
   return 0;

    
    
}



int userInput(){
    
   char x;
   printf("Enter number: ");
   scanf("%c", &x);
   printf("Number is %c \n", x);
   return x;
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
