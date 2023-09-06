#include "student_struct.h"


void student_struct_swap(std_t* ptr1, std_t* ptr2)
{
    std_t temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void student_struct_print(const std_t* ptr, int index)
{
    printf("|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| %2d | %-20s | %2d |   %1c   |  %3d   | %11s | %-20s | %11s  | %-20s | %11s  |\n",
           index, ptr->name, ptr->id, ptr->Class, ptr->degree, ptr->phone, ptr->father_name, ptr->father_phone, ptr->mother_name, ptr->mother_phone);
}

void student_struct_scan(std_t* ptr, std_t* ptr2, int current_position)
{
    printf("Enter student name: ");
    fflush(stdin);
    string_scan(ptr->name, 21);

    int flag = 1;
    while(flag)
    {
        int id = 1;
        flag = 0;
        printf("Enter student ID: ");
        scanf("%d",&id);
        if(id <= 0)
        {
            printf("\n\nIDs starts from 1\n\n");
            Sleep(5000);
            flag = 1;
        }
        else
        {
            for(int counter = 0; counter < current_position; counter++)
            {
                if(ptr2[counter].id == id)
                {
                    printf("\nThis ID already exist addtion failed\nChoose ID out of those\n");
                    for(int counter2 = 0; counter2 < current_position; counter2++)
                    {
                        printf(" %d ", ptr2[counter2].id);
                    }
                    printf("\n\n");
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                ptr->id = id;
            }
        }

    }
    flag = 1;

    while(flag)
    {
        char chr;
        flag = 0;
        printf("Enter student class(one character): ");
        fflush(stdin);
        scanf("%c", &chr);
        if(chr >= 'a' && chr <= 'z')
        {
            chr -= ('a' - 'A');
        }
        else if(!(chr >= 'A' && chr <= 'Z') && !(chr >= '1' && chr <= '9'))
        {
            printf("\nClass must be character (A... or 1...)\n\n");
            flag = 1;
        }
        if(!flag)
        {
            ptr->Class = chr;
        }
    }

    flag = 1;
    while(flag)
    {
        int deg;
        flag = 0;
        printf("Enter student degree(0:100): ");
        scanf("%d", &deg);

        if(deg < 0 || deg > 100)
        {
            printf("\nDegrees starts from 0 to 100\n\n");
            flag = 1;
        }
        else
        {
            ptr->degree = deg;
        }
    }

    printf("Enter student phone: ");
    string_scan(ptr->phone, 12);

    printf("Enter Father name: ");
    string_scan(ptr->father_name, 21);
    printf("Enter father phone: ");
    string_scan(ptr->father_phone, 12);

    printf("Enter Mother name: ");
    string_scan(ptr->mother_name, 21);
    printf("Enter mother phone: ");
    string_scan(ptr->mother_phone, 12);
}





void student_struct_remove(std_t *ptr, int size)
{
    for(int counter = 0; counter < size - 1; counter++)
    {
        student_struct_swap(ptr, ptr + 1);
    }
    printf("Remove done\n");
}


void student_struct_edit_data(std_t *ptr, std_t *ptr2, int current_position)
{
    int choice = 0;
    printf("Choose data that you want edit: \n");
    printf("1- Student name.\n2- Student ID.\n3- Student class.\n4- Student phone.\n5- Father name.\n");
    printf("6- Father phone.\n7- Mother name.\n8- Mother phone.\n9- Change all data.\n\nEnter your choice 1,2,3,4,5,6,7,8 or 9: ");
    scanf("%d", &choice);
    int id, flag = 0;
    switch(choice)
    {
    case 1:
        printf("Enter new name: ");
        string_scan(ptr->name, 21);
        printf("Edition done\n");
        break;
    case 2:
        printf("Enter new ID: ");
        scanf("%d",&id);
        for(int counter = 0; counter < current_position; counter++)
        {
            if(ptr2[counter].id == id)
            {
                printf("This ID already exist edition failed\n");
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            ptr->id = id;
            printf("Edition done\n");
        }
        break;
    case 3:
        printf("Enter new class: ");
        fflush(stdin);
        scanf("%c", &ptr->Class);
        printf("Edition done\n");
        break;
    case 4:
        printf("Enter new phone: ");
        string_scan(ptr->phone, 12);
        printf("Edition done\n");
        break;
    case 5:
        printf("Enter new father name: ");
        string_scan(ptr->father_phone, 12);
        printf("Edition done\n");
        break;
    case 6:
        printf("Enter new father phone: ");
        string_scan(ptr->father_phone, 12);
        printf("Edition done\n");
        break;
    case 7:
        printf("Enter new mother name: ");
        string_scan(ptr->mother_phone, 12);
        printf("Edition done\n");
        break;
    case 8:
        printf("Enter new mother phone: ");
        string_scan(ptr->mother_phone, 12);
        printf("Edition done\n");
        break;
    case 9:
        student_struct_scan(ptr, ptr2, current_position);
        printf("Edition done\n");
        break;
    default:
        printf("invalid input!!!\n");
    }
}







void student_struct_sort_by_ID(std_t *arr_school, int size)
{
    int choice = 0, counter1, counter2, flag = 1;
    printf("\n1- Ascending.\n2- Descending.\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].id < arr_school[counter2].id)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("The students were sorted in ascending order according to their IDs\n");
        Sleep(500);
        break;
    case 2:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].id > arr_school[counter2].id)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("The students were sorted in descending order according to their IDs\n");
        Sleep(500);
        break;
    default:
        printf("Invalid input !!! no change\n");
    }
}






void student_struct_sort_by_degree(std_t *arr_school, int size)
{
    int choice = 0, counter1, counter2, flag = 1;
    printf("\n1- Ascending.\n2- Descending.\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].degree > arr_school[counter2].degree)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("The students were sorted in ascending order according to their degrees\n");
        Sleep(500);
        break;
    case 2:
        for(counter1 = 0; counter1 < size && flag; counter1++)
        {
            flag = 0;
            for(counter2 = 0; counter2 < size - 1 - counter1; counter2++)
            {
                if(arr_school[counter2 + 1].degree < arr_school[counter2].degree)
                {
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                    flag = 1;
                }
            }
        }
        printf("The students were sorted in descending order according to their degrees\n");
        Sleep(500);
        break;
    default:
        printf("Invalid input !!! no change\n");
    }
}







void student_struct_sort_by_name(std_t *arr_school, int size)
{
    int choice = 0, counter1 = 0, counter2 = 0, flag = 1;
    printf("\n1- Ascending.\n2- Descending.\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        for(int counter = 0; counter < size && flag; counter++)
        {
            flag = 0;
            for(int counter2 = 0; counter2 < size - counter - 1; counter2++)
            {
                if(string_compare_sort(arr_school[counter2].name, arr_school[counter2 + 1].name) == 1)
                {
                    flag = 1;
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                }
            }
        }
        printf("The students were sorted in ascending order according to their names\n");
        Sleep(500);
        break;
    case 2:
        for(int counter = 0; counter < size && flag; counter++)
        {
            flag = 0;
            for(int counter2 = 0; counter2 < size - counter - 1; counter2++)
            {
                if(string_compare_sort(arr_school[counter2].name, arr_school[counter2 + 1].name) == -1)
                {
                    flag = 1;
                    student_struct_swap(&arr_school[counter2], &arr_school[counter2 + 1]);
                }
            }
        }
        printf("The students were sorted in descending order according to their names\n");
        Sleep(500);
        break;
    default:
        printf("Invalid input !!! no change\n");
    }
}
