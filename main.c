/********************************************************************
* Program: C-pointer_arrays_functions                               *
* About  : This is a collection of different function I was messing *
*          with and creating throw my learnings of pointers and     *
*          arrays.                                                  *
*                                                                   *
* Author : Ammar MULLAOGLU                                          *
* Date   : 29.10.2026                                               *
*********************************************************************/

//Preprocessors MACROS
//////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COLUMN 3
#define ROW 3
//////////////////////////////////////////////////////////////////////

//Prototypes
//////////////////////////////////////////////////////////////////////
void set_zero(int arr[], int length);                               //Sets 1D array's elements to zero
void print_arr(int arr[], int length);                              //Prints 1D array's elements.
int* find_largest(int arr[], int length);                           //Finds the largest element in a 1D array.
void print_column_2d_array(int row_no, int column_no, int arr[row_no][column_no], int column_to_print);         //Prints and only prints a specific column of a 2D array.
void return_column_from_2d(int row_no, int column_no, int arr[row_no][column_no], int column_to_get, int result_array[]); //Gets a specific column from a 2D array and stores it in a 1D array.
void return_row_from_2d(int row_no, int column_no, int arr[row_no][column_no], int row_to_get, int result_array[]);       //Gets a specific row from a 2D array and stores it in a 1D array.
int sum_array(const int arr[], int length);
bool search(const int arr[], int length, int key);
int inner_product(const int *a, const int *b, int length);
/////////////////////////////////////////////////////////////////////

int main(void){
    system("title C-pointer_array_functions");

    printf( "/********************************************************************\n"
            "* Program: C-pointer_arrays_functions                               *\n"
            "* About  : This is a collection of different function I was messing *\n"
            "*          with and creating throw my learnings of pointers and     *\n"
            "*          arrays.                                                  *\n"
            "*          Press Q or q to terminate the program.                   *\n"
            "*                                                                   *\n"
            "* Author : Ammar MULLAOGLU                                          *\n"
            "* Date   : 29.10.2026                                               *\n"
            "*********************************************************************/\n\n\n");


    int arr[ROW][COLUMN] = {
    {17, 82, 34},
    {56, 11, 93},
    {48, 67, 25}
    };

    printf("This is the example array we are having here: \n");
    printf("\narr %dx%d:\n", ROW, COLUMN);
    for(int i = 0; i < ROW; i++){
        printf("\t");
        for(int j = 0; j < COLUMN; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }printf("\n\n");

    int columns_arr[COLUMN];
    int row_arr[ROW];

    //Put your code under here
    ////////////////////////////////////////////////
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    print_arr(a, 5);
    printf("\n");
    print_arr(b, 5);
    printf("\n\nThe inner product of a[] = %d\n", inner_product(a, b, 5));

    return 0;
}

void set_zero(int arr[], int length){
    for(int i = 0; i < length; i++)
        arr[i] = 0;

    return;
}

void print_arr(int arr[], int length){
    for(int i = 0; i < length; i++)
        printf("%d ", arr[i]);

    return;
}

int* find_largest(int arr[], int length){
    int result = arr[0];
    int index = 0;

    for(int i = 0; i < length; i++){
        if(result < arr[i]){
            result = arr[i];
            index = i;
        }
    }

    return &arr[index];
}

void print_column_2d_array(int row_no, int column_no, int arr[row_no][column_no], int column_to_print){
    //in calling this function if you want the third column to print you don't need
    //to call it as it is index which is 2, call it as 3, it is fine.

    column_to_print--;
    int (*ptr)[column_no] = arr;
    for( ; ptr < arr + row_no; ptr++)
        printf("%d\n", *(*ptr + column_to_print));

    return;
}

void return_column_from_2d(int row_no, int column_no, int arr[row_no][column_no], int column_to_get, int result_array[]){
    int index = 0;
    column_to_get--;
    int (*ptr)[column_no] = arr;
    for( ; ptr < arr + row_no; ptr++)
        result_array[index++] = *(*ptr + column_to_get);

    return;
}

void return_row_from_2d(int row_no, int column_no, int arr[row_no][column_no], int row_to_get, int result_array[]){
    row_to_get--;
    for(int i = 0; i < column_no; i++){
        result_array[i] = arr[row_to_get][i];
    }
    return;
}

int sum_array(const int arr[], int length){
    int sum = 0;
    for(int *ptr = arr; ptr < arr + length; ptr++)
        sum += *ptr;

    return sum;
}

bool search(const int arr[], int length, int key){
    for(int *ptr = arr; ptr < arr + length; ptr++){
        if(*ptr == key)
            return true;
    }
    return false;
}

int inner_product(const int *a, const int *b, int length){
    int sum = 0;
    int *ptr1 = a, *ptr2 = b;
    for(; ptr1 < a + length; ptr1++){
        sum += (*ptr1) * (*ptr2++);
    }
    return sum;
}
