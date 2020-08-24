#include "ex1102a.hpp"
#include <cstring>

using namespace std;

void ex1102a()
{
    
    constexpr int size = 10;
    // pointer to a single character
    char * p;
    // array of 10 integers on the stack
    int array[size];
    // array of 10 integers on the heap 
    int * aptr {new int[size]};
    // array of strings (pointer to a char * which is a string)
    char* stringArray[6];
    // array of strings, pointer to pointer , difference from above is the fixed
    // size 
    char ** stringPtr;
    const int constant{9};
    // pointer to constant integer, the value of the pointer can change , not
    // the value pointed by the pointer
    const int * ptrCons ;
    ptrCons= &size; // this works 
    /*ptrCons= size; fails to compile */
    const int  * const consPtr = &size; // initialization 
    /*consPtr= &constant; fails to compile trying to modify the ptr address */

    char single_char = 'A'; // init single  char
    p = &single_char;
    // init pointer to char
    
    for (int i = 0 ; i < size; ++i)
    {
        array[i] = i; // init stack array of init 
        aptr[i] = i; // init heap array of init 
         // init string of char 
        
    }
    char h = 'H';
    char e = 'E';
    char l = 'l';
    char o = 'O';
    char terminate = '\0';
    stringArray[0] =  &h;
    stringArray[1] =  &e;
    stringArray[2] =  &l;
    stringArray[3] =  &l;
    stringArray[4] =  &o;
    stringArray[5] =  &terminate;

    stringPtr = (char **) stringArray;
    cout << **stringPtr << endl;
    cout << **(stringPtr+1) << endl;
    ptrCons = &constant;
}