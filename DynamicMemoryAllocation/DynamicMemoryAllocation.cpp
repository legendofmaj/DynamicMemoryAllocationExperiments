#include <iostream>

using namespace std;

//Global Variables
int* numbers; //Pointer to a numbers array.
string* strings; //Pointer to a string array.

void fillArrays(int numNumbers, int numStrings) 
{
    numbers = new int[numNumbers]; //Allocate memory for numbers once the function is called.
    strings = new string[numStrings]; //Allocate memory for strings once the function is called.

    for (int i=0; i < numNumbers; i++) 
    {
        numbers[i] = i;
    }
    for (int i=0; i < numStrings; i++)
    {
        strings[i] = "string";
    }

}

int main () 
{
    int numNumbers;
    int numStrings;
    cout << "Input number of numbers first, number of strings second" << endl;
    cin >> numNumbers;
    cin >> numStrings;

    fillArrays(numNumbers, numStrings);

    //print Arrays
    cout << "numbers:" << endl;
    for (int i=0; i < numNumbers; i++) 
    {
        cout << numbers[i] << endl;
    }
    cout << "strings:" << endl;
    for (int i=0; i < numStrings; i++)
    {
        cout << strings[i] << endl;
    }

    //Deallocate memory
    delete[] numbers;
    delete[] strings;

    return 0;
}