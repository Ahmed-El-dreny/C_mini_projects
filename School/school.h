#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED


#include "student_struct.h"


#define SCHOOL_CAPACITY 50

void school_print(void);

void school_add_student(void);

void school_remove_student_byID(void);

void school_remove_student_by_name(void);

void school_edit_student_data_byID(void);

void school_sort(void);

void school_clear(void);

void school_current_size(void);

void school_data_save_in_file(void);

void school_data_read_from_file(void);

#endif // SCHOOL_H_INCLUDED
