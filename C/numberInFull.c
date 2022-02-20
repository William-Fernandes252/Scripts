/* Prints a number up to 20 in full. */

#include<stdio.h>

int main(void){

    int ten, unit;

    printf("Enter a number with up to two digits: ");
    scanf("%1d%1d", &ten, &unit);

    printf("You entered ");

    if(ten == 1 && unit == 1){
        printf("eleven.\n");
    }
    else if(ten == 1 && unit == 2){
        printf("twelve.\n");
    }
    else if(ten == 1 && unit == 3){
        printf("thirteen.\n");
    }
    else if(ten == 1 && unit == 4){
        printf("fourteen.\n");
    }
    else if(ten == 1 && unit == 5){
        printf("fifteen.\n");
    }
    else if(ten == 1 && unit == 6){
        printf("sixteen.\n");
    }
    else if(ten == 1 && unit == 7){
        printf("seventeen.\n");
    }
    else if(ten == 1 && unit == 8){
        printf("eighteen.\n");
    }
    else if(ten == 1 && unit == 9){
        printf("nineteen.\n");
    }
    else{

        switch(ten){
            case 9: printf("ninety-"); break;
            case 8: printf("eighty-"); break;
            case 7: printf("seventy-"); break;
            case 6: printf("sixty-"); break;
            case 5: printf("fifty-"); break;
            case 4: printf("fourty-"); break;
            case 3: printf("thirty-"); break;
            case 2: printf("twenty-"); break;
            case 0: printf(""); break;
        }

        switch(unit){
            case 9: printf("nine.\n"); break;
            case 8: printf("eight.\n"); break;
            case 7: printf("seven.\n"); break;
            case 6: printf("six.\n"); break;
            case 5: printf("five.\n"); break;
            case 4: printf("four.\n"); break;
            case 3: printf("three.\n"); break;
            case 2: printf("two.\n"); break;
            case 1: printf("one.\n"); break;
            default: printf(".\n"); break;
        }
    }

    return 0;
}
