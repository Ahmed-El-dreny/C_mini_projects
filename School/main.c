#include "school.h"


int main(void)
{
    int flag = 1;

    school_data_read_from_file();

    while(flag)
    {
        system("cls");
        int choice = 0,rem_choice = 0;
        printf("1- Add student.\n2- Remove student.\n3- Edit student data\n4- Print all student in school.\n5- Sort\n6- delete all data\n7- School capacity and student number.\n8- exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            school_add_student();
            school_data_save_in_file();
            break;
        case 2:
            system("cls");
            printf("Remove by:\n1-ID\n2-Student name\n\n");
            printf("Enter choice: ");
            scanf("%d", &rem_choice);
            switch(rem_choice)
            {
            case 1:
                school_remove_student_byID();
                break;
            case 2:
                school_remove_student_by_name();
                break;
            default:
                printf("invalid input no change\n");
            }
            school_data_save_in_file();
            break;
        case 3:
            school_edit_student_data_byID();
            school_data_save_in_file();
            break;
        case 4:
            school_print();
            break;
        case 5:
            school_sort();
            school_data_save_in_file();
            break;
        case 6:
            school_clear();
            school_data_save_in_file();
            break;
        case 7:
            school_current_size();
            break;
        case 8:
            flag = 0;
            break;
        default:
            printf("invalid input !!!");
        }
    }

    return 0;
}
