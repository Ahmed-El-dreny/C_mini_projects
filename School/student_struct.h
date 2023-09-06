#include "string.h"

#include <windows.h>

typedef struct student{

    int degree;
    int id;
    char name[21];
    char Class;
    char phone[12];
    char father_name[21];
    char father_phone[12];
    char mother_name[21];
    char mother_phone[12];

}std_t;




void student_struct_print(const struct student* ptr, int index);

void student_struct_scan(struct student* ptr, std_t* ptr2, int current_position);

void student_struct_remove(std_t *ptr, int size);

void student_struct_edit_data(std_t *ptr, std_t *ptr2, int current_position);

void student_struct_sort_by_ID(std_t *arr_school, int size);

void student_struct_sort_by_degree(std_t *arr_school, int size);

void student_struct_sort_by_name(std_t *arr_school, int size);
