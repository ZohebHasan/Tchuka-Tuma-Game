#include <stdio.h>
#include <stdbool.h>

//Declarations
bool isValidSectionNum(int section);
void printBoard( int *board, int length);
void makeMove(int *board, int section);
// bool hasWon(int *board);
// bool hasLost(int *board);
int promptForMove();


int promptForMove(){
    int section;
    
    printf("Choose a section (1-4):_ ");
    scanf("%d" , &section); 
    while(isValidSectionNum(section) == false){
        printf("Invalid choice. Choose a section (1-4):_ ");
        scanf("%d" , &section);
    }
    return section;
}


void makeMove(int *board, int section){
    int temp;
    if( board[section] == 0){
        return;
    }
    else{
        temp = board[section];
        switch(section){

            case 1:
                board[section] = 0;
                for(int i = temp; i > 0 ; i--){
                    temp++;
                    board[temp]++; 
                }
                printBoard(board,5); //For Testing
                break;
               
            case 2:

            // case 3:

            // case 4:

            // default:


        }
  
    }
    
    
}

void printBoard( int *board, int length){
    for(int i = 0; i < length; i++){
        if(i < 4){
            printf("%d ", board[i]);
        }
        else{ 
            printf("| %d\n",  board[i]);   
        }
    }
}

bool isValidSectionNum(int section){
    if(section > 4 || section < 1){
        return false;
    }
    return true;
}

int main() {
    int board[5] = {2, 2, 2, 2, 0};
    int length = sizeof(board) / sizeof(board[0]);
    // while(hasWon(board) == true || hasLost(board) == true){
        printBoard(board,length);
        makeMove(board, promptForMove());
        
    // }
    return 0;
}
