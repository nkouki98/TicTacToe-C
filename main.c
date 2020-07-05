
#include <stdio.h>
#include <stdlib.h>



void displayBoard(int grid[3][3]);
void displayInput(int grid[3][3]);

int userInput();


int main(){

   
   int grid[3][3];
   int i,j,c;
   char str[10];
   int counter=1;
   int num;
   
   for(i=0;i<3;i++)
   {    
       for(j=0;j<3;j++){
           grid[i][j] = counter;
           printf("grid[%d][%d] = %d\n", i,j, grid[i][j] );   
           counter++;
       }
   }

   displayBoard(grid);
   num = userInput();
   char cnum = num;
   printf("char is %d\n", cnum);
   printf("%d\n", num);
 
    for(i=0;i<3;i++)
   {    
       for(j=0;j<3;j++){
   
           if(grid[i][j] == num)
            grid[i][j] = 'X';
            printf("grid[%d][%d] = %d\n", i,j, grid[i][j] ); 
             
      
       }
   }


   displayInput(grid);
   return 0;

    
    
}



int userInput(){
    
   int x;
   printf("Enter number: ");
   scanf("%d", &x);
   printf("Number is %d \n", x);
   return x;
}



void displayBoard(int grid[3][3]){

   printf("\n\n\tTic Tac Toe\n\n");



   printf("     |     |     \n");
   printf(" %d   |  %d  |  %d   \n", grid[0][0], grid[0][1], grid[0][2]);


   

   printf("_____|_____|_____\n");
   printf("     |     |     \n");

   printf(" %d   |  %d  |  %d   \n", grid[1][0], grid[1][1], grid[1][2]);

 
   printf("_____|_____|_____\n");
   printf("     |     |     \n");
    
   printf(" %d   |  %d  |  %d   \n", grid[2][0], grid[2][1], grid[2][2]);
   printf("     |     |     \n\n");
}


void displayInput(int grid[3][3]){

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
