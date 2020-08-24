/**Write a program that asks input from the keyboard and prints the result on the screen and writes it to a file. 
The question is: “What is your age?”*/
#include "ex1101.hpp"
using namespace std;
void print_string(ostream &s ,const string& input_string)
{
    s << input_string << endl;
}

void ex1101(void)
{   
    cout << "Write a program that asks input from the keyboard and prints the result on the screen and writes it to a file." 
         << "The question is: “What is your age?.\n";
    string age_string("");
    const string prompt("What is your age?");
    ofstream age_file("ex1101.txt");
    print_string(cout,prompt);
    cin >> age_string;
    print_string(age_file,age_string);

}