#include <stdio.h>
#include <stdbool.h>

//Declarations
bool isValidSectionNum(int section);

bool isValidSectionNum(int section){
    if(section > 4 || section < 0){
        return false;
    }
    return true;
}

int main() {
    int section;
    printf("Choose a section (1-4):_ ");
    scanf("%d" , &section);
    if(isValidSectionNum(section) == false){
        while(isValidSectionNum(section) == false){
            printf("Invalid choice. Choose a section (1-4):_ ");
            scanf("%d" , &section);
        }
        
    }

    return 0;
}
