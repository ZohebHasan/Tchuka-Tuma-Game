#include <stdio.h>
#include <stdbool.h>

//Declarations
bool isValidSectionNum(int section);
int length(int arr[]);



bool isValidSectionNum(int section){
    if(section > 4 || section < 1){
        return false;
    }
    return true;
}

int main() {
    int board[5] = {2, 2, 2, 2, 0};
    int section;
    int length = sizeof(board) / sizeof(board[0]);
    for(int i = 0; i < length; i++){
        if(i <= 4){
            printf("%d ", board[i]);
        }
        printf(" | %d",  board[i]);    
    }
    printf("Choose a section (1-4):_ ");
    scanf("%d" , &section); 
    while(isValidSectionNum(section) == false){
        printf("Invalid choice. Choose a section (1-4):_ ");
        scanf("%d" , &section);
    }


    

    return 0;
}
