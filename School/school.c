#include "school.h"

static std_t arr_school[SCHOOL_CAPACITY];

static unsigned int current_size;

static FILE *school_data = NULL;

int line_size = 0;






void school_print(void)
{
    system("cls");
    if(0 == current_size)
    {
        printf("No students yet\n");
    }
    else
    {
        printf("*-------------------------------------------------------------------------------------------------------------------------------------------*\n");
        printf("| No | Student Name         | ID | Class | Degree |    Phone    | Father name          | Father Phone | Mother name          | Mother Phone |\n");
        for(int counter = 0; counter < current_size; counter++)
        {
            student_struct_print(&arr_school[counter], counter + 1);
        }
        printf("*-------------------------------------------------------------------------------------------------------------------------------------------*\n");
    }
    printf("\nPress any key to return: ");

    fflush(stdin);
    getchar();
}





void school_add_student(void)
{
    system("cls");
    if(50 > current_size)
    {
        student_struct_scan(&arr_school[current_size++], arr_school, current_size);
    }
    else
    {
        printf("School is full\n");
    }
}





void school_remove_student_byID(void)
{
    system("cls");
    if(0 < current_size)
    {
        int id = 0, flag = 1;
        printf("Enter ID: ");
        scanf("%d", &id);
        for(int counter = 0; counter < current_size; counter++)
        {
            if(arr_school[counter].id == id)
            {
                student_struct_remove(&arr_school[counter], --current_size);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("NOT FOUND\n");
            Sleep(5000);
        }
    }
    else
    {
        printf("School is empty.");
        Sleep(5000);
    }
}





void school_remove_student_by_name(void)
{
    system("cls");
    if(0 < current_size)
    {
        char str[21], flag = 1;
        string_scan(str, 21);
        for(int counter = 0; counter < current_size; counter++)
        {
            if(string_compare_for_search(str, arr_school[counter].name))
            {
                student_struct_remove(&arr_school[counter], --current_size);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("NOT FOUND\nBe aware the program is case sensitive\n");
            Sleep(5000);
        }
    }
    else
    {
        printf("School is empty.");
    }
}





void school_edit_student_data_byID(void)
{
    system("cls");
    int id, flag = 1;
    printf("Enter ID: ");
    scanf("%d", &id);
    for(int counter = 0; counter < current_size; counter++)
    {
        if(arr_school[counter].id == id)
        {
            student_struct_edit_data(&arr_school[counter], arr_school, current_size);
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        printf("This ID not exist\n");
        Sleep(5000);
    }
}




void school_sort(void)
{
    system("cls");
    int choice = 0;
    printf("1- Sort all student by ID.\n2- Sort all student by degree.\n3- all student by name.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        student_struct_sort_by_ID(arr_school, current_size);
        break;
    case 2:
        student_struct_sort_by_degree(arr_school, current_size);
        break;
    case 3:
        student_struct_sort_by_name(arr_school, current_size);
        break;
    default:
        printf("Invalid input !!! no change\n");
    }
}




void school_clear(void)
{
    system("cls");
    current_size = 0;
    printf("ALL DATA DELETED\n");
    Sleep(5000);
}





void school_current_size(void)
{
    system("cls");
    printf("Number of students in school = %d\n\n", current_size);
    printf("School capacity = %d\n", SCHOOL_CAPACITY);
    Sleep(5000);
}






void school_data_save_in_file(void)
{
    school_data = fopen("School_data.txt", "w");
    fprintf(school_data,"Total number of students = %d\n", current_size);
    fprintf(school_data, "*-------------------------------------------------------------------------------------------------------------------------------------------* \n");
    fprintf(school_data, "| No | Student Name         | ID | Class | Degree |    Phone    | Father name          | Father Phone | Mother name          | Mother Phone |\n");
    for(int counter = 0; counter < current_size; counter++)
    {
        fprintf(school_data, "|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
        fprintf(school_data, "| %-2d | %-20s | %-2d |   %1c   |  %-3d   | %11s | %-20s | %11s  | %-20s | %11s  |\n",
                counter + 1, arr_school[counter].name, arr_school[counter].id, arr_school[counter].Class, arr_school[counter].degree, arr_school[counter].phone,
                arr_school[counter].father_name, arr_school[counter].father_phone, arr_school[counter].mother_name, arr_school[counter].mother_phone);
    }
    fprintf(school_data, "*-------------------------------------------------------------------------------------------------------------------------------------------* \n");

    fclose(school_data);
}





void school_data_read_from_file(void)
{
    school_data = fopen("School_data.txt", "r");

    if(NULL != school_data)
    {
        char arr_read[143] = {0};

        fgets(arr_read, 142, school_data);
        string_copy_charTOint(&arr_read[27], &current_size, 2);

        fgets(arr_read, 143, school_data);
        fgets(arr_read, 143, school_data);
        fgets(arr_read, 143, school_data);

        for(int counter = 0; counter < current_size; counter++)
        {
            fgets(arr_read, 143, school_data);
            fgets(arr_read, 143, school_data);

            string_copy(&arr_read[7], arr_school[counter].name, 20);
            string_copy_charTOint(&arr_read[30], &arr_school[counter].id, 2);
            string_copy(&arr_read[37], &arr_school[counter].Class, 1);
            string_copy_charTOint(&arr_read[44], &arr_school[counter].degree, 3);
            string_copy(&arr_read[52], arr_school[counter].phone, 11);
            string_copy(&arr_read[66], arr_school[counter].father_name, 20);
            string_copy(&arr_read[89], arr_school[counter].father_phone, 11);
            string_copy(&arr_read[104], arr_school[counter].mother_name, 20);
            string_copy(&arr_read[127], arr_school[counter].mother_phone, 11);
        }
    }
    fclose(school_data);
}



