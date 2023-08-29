#include "soduko.h"

int main(void)
{
    init_soduko();
    welcome_mas();

    int col, row, opr, flag = 1;
    char num;

    while(is_finsh())
    {
        Sleep(500);
        system("cls");

        print_soduko();

        flag = 1;

        printf("Enter row number and column number and number to add or change by it\n\n");

        printf("Enter row number: ");
        scanf("%d", &row);

        printf("Enter column number: ");
        scanf("%d", &col);

        fflush(stdin);
        printf("Enter number: ");
        scanf("%c", &num);
        fflush(stdin);

        printf("\n");

        printf("Choose the operation:\
               \n1- Edit number\
               \n2- Add number\
               \n3- Give up and exit\n\
               \nChoose: ");
        scanf("%d", &opr);

        printf("\n\n");

        switch(opr)
        {
        case 1:
            if(edit_num(num, row, col))
            {
                printf("Number edited\n");
            }
            break;

        case 2:
            if(set_num(num, row, col))
            {
                printf("Number added\n");
                flag = 0;
            }
            break;

        case 3:
            system("cls");
            lose_mas();
            return 0;

        default:
            printf("Invalid input");
        }
    }

    system("cls");
    win_mas();

    return 0;
}
