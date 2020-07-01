
#include <stdio.h>
#include <stdlib.h>



int userInput();

void displayBoard(unsigned char grid[3][3]);

void main(){

    unsigned char grid[3][3] = {'_','8','_','_','_','_','_','_','_'};
    
    displayBoard(grid);
    
}


void arrayGrid(){

    unsigned char grid[3][3] = {'_','_','_','_','_','_','_','_','_'};
}

int userInput(){
    
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Number is %d \n", x);
    return x;
}



void displayBoard(unsigned char grid[3][3]){

   

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



