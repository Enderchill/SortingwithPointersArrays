#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> // contains prototype for function time
using namespace std;

#define SIZE 40

void printArray(int randArray[]);    // Function prototype
void bubbleSort(int* list[]);        // Function prototype
void printPointerArray(int* ptrArray[]);    // Function prototype
void swapIntPtr(int** xptr, int** yptr);    // Function prototype

int main()
{

    int seed ;
    cout << "Enter seed: ";
    cin >> seed;
   srand(seed );

    int dataArray[SIZE] = { 0 };
    int* pointerArray[SIZE];
    
    // Initializing values in Data Array
    for (int index = 0; index < SIZE; index++)
    {
        dataArray[index] = rand() % 3000;
    }

    // Printing four different data sets
    printf("Before Sorting, values in Data Array: \n");
    printArray(dataArray);
    printf("\n");

    // Initializing Pointer array with the address of each element in data array
    {
        for(int i = 0; i < SIZE;i++)
        {
            pointerArray[i] = &dataArray[i];
        }
            
    }
    

    printf("Before Sorting, values in Pointer Array and the value it is pointing at: \n");
    printPointerArray(pointerArray);
    printf("\n");

    // Calling function Bubble SOrt
    bubbleSort(pointerArray);

    // After Sorting printing the values
    printf("\n");
    printf("After Sorting, values in Pointer Array and the value it is pointing at:  \n");
    printPointerArray(pointerArray);
    printf("\n");
    

    printf("\n");
    printf("After Sorting, values in Data Array: \n");
    printArray(dataArray);
    printf("\n");
   return 0;
}

// complete both the print functions and bubbleSort.
//Call the swapIntPrt function from Bubble sort for swapping the

void printArray(int randArray[])
{
    for(int i = 0;i<SIZE;i++)
    {
        if(i % 10 == 0)
        {
            cout << endl;
        }
        cout << left << setw(6)<< randArray[i];
    }
    
}
void bubbleSort(int* list[])
{
    for (int i = SIZE - 1; i > 0;i--)
    {
        
        for (int j = 0; j <= i - 1;j++)
        {
            if (*list[j] > *list[j + 1])
            {
                swapIntPtr(&list[j], &list[j + 1]);
            }
        }
    }
    
}
void printPointerArray(int* ptrArray[])
{
    for(int i = 0;i<SIZE;i++)
    {
        if(i % 10 == 0)
        {
            cout << endl;
        }
        cout << left << setw(6)<< *ptrArray[i];
    }
    
}
void swapIntPtr(int** xptr, int** yptr)
{
    int *temp = *xptr;
    *xptr = *yptr;
    *yptr = temp;
}
