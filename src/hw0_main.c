#include <stdio.h>
#include <stdbool.h>


//Declarations
int losingSection;
bool lost = false;
bool won = false;
bool isValidSectionNum(int section);
void printBoard( int *board, int length);
void makeMove(int *board, int section);
bool hasWon();
bool hasLost();
int promptForMove();

bool hasWon(){ 
    if(won == true){
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


int promptForMove(int *board){
    int section;
    
    printf("Choose a section (1-4): ");
    scanf("%d" , &section); 
    while(isValidSectionNum(section) == false || board[section-1] == 0){
        printf("Invalid choice. Choose a section (1-4): ");
        scanf("%d" , &section);
    }
    return section;
}


void makeMove(int *board, int section){
    int counters; 
    counters = board[section];
    board[section] = 0;
        while(counters > 0){ 
            if(section == 4){
                    section = -1;
            }
            section++;                   
            board[section]++;
            counters--;
            if( counters == 0){
                if(board[section] == 1 && section != 4){ //lost
                        lost = true;
                        losingSection = section;
                        return;
                }
                int flag = 0;
                for(int i = 0; i < 4 ; i++){      
                    if(board[i] == 0){
                        flag++;               
                    }
                    if(flag == 4){
                        won = true;
                        return;
                    }
                }
                if( section == 4){ // Ruma                
                    return;
                }
                else if(board[section] != 0) { //landed on a section with existing counters
                    while(board[section] != 0 && section != 4){ // should seperate the ruma logic
                        if(board[section] == 1 && section != 4){ //lost
                            lost = true;
                            losingSection = section;
                            return;
                        }
                        printBoard(board,5);
                        printf("Last piece landed in section %d. Continue sowing seeds!\n", section + 1);
                        counters = board[section];
                        board[section] = 0;
                        while(counters > 0){
                            if(section == 4){
                                section = -1;
                            }
                            section++;
                            board[section]++;
                            counters--;                            
                            }
                    }
                }
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
    int section;

    while(hasWon() != true && hasLost() != true){
        printBoard(board,length);
        section = promptForMove(board) - 1;     
        makeMove(board, section);
        if(hasLost() == true){
            printBoard(board, 5);
            printf("You lost because the last counter fell into section %d.\n", losingSection + 1);
        }
        else if(hasWon() == true){
            printf("You Won!\n");
        }
    }   
    return 0;
}
