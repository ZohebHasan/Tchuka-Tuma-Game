#include <stdio.h>
#include <stdbool.h>


//Declarations
bool lost = false;
bool isValidSectionNum(int section);
void printBoard( int *board, int length);
// void makeMove(int *board, int section);
bool hasWon(int *board);
bool hasLost();
int promptForMove();

bool hasWon(int *board){ //Needs Revision
    if( board[4] == 7 && board[3] == 1){
        printBoard(board,5);
        printf("You won!");
        return true;
    }
    return false;
}

bool hasLost(){
    if (lost == true){
        return true;
    }
    return false;
}


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


// void makeMove(int *board, int section){
//     int counters;
//     if(board[section] == 0){
//         return;
//     }
//     else{
//         counters = board[section];
//         board[section] = 0;
//             while(counters > 0){ 
//                 section++;                   
//                 board[section]++;
//                 counters--;
//                 // if(section == 4){
//                 //     section = -1; //POTENTIAL VULNARABILITY!!
//                 // }
//                 if( counters == 0){
//                     if( section == 4){ // Ruma
//                         return;
//                     }
//                     else if(board[section] != 0) { //landed on a section with existing counters
//                         printf("Last piece landed in section %d. Continue sowing seeds!\n", section + 1);
//                         counters = board[section];
//                         while(counters > 0){
//                             section++;
//                             board[section]++;
//                             counters--;
//                         }
//                     }
//                     else if(board[section + 1] == 0){ //lost
//                         lost = true;
//                         return;
//                     }
//                 }
//             }
//                 // printBoard(board,5); //For Testing
//     }   
// }

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

    // while(hasWon(board) != true || hasLost() != true){
        printBoard(board,length);
        int section = promptForMove() - 1;

    int counters;
    if(board[section] == 0){
        return;
    }
    else{
        counters = board[section];
        board[section] = 0;
            while(counters > 0){ 
                section++;                   
                board[section]++;
                counters--;
                // if(section == 4){
                //     section = -1; //POTENTIAL VULNARABILITY!!
                // }
                if( counters == 0){
                    if( section == 4){ // Ruma
                        return;
                    }
                    else if(board[section] != 0) { //landed on a section with existing counters
                        printf("Last piece landed in section %d. Continue sowing seeds!\n", section + 1);
                        counters = board[section];
                        while(counters > 0){
                            section++;
                            board[section]++;
                            counters--;
                        }
                    }
                    else if(board[section + 1] == 0){ //lost
                        lost = true;
                        return;
                    }
                }
            }
                // printBoard(board,5); //For Testing
    }        
    // }
    return 0;
}
