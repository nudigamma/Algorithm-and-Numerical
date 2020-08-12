/**program demonstrate the inheritance of output stream to specialized objects */
#include "some_stream_manip.hpp"

using namespace std;

void write_something(ostream &s)
{
    s << "Hi stream, did you know that 3*3 = " << 3*3 << endl;
}

void some_stream_manip()
{
    cout << "Start: Showcasing stream inheritance\n";
    ofstream myfile("streamfile.txt");
    stringstream streamstring;
    cout <<"Using the same function that takes as argument an ostream object We can :" << endl;  
    cout <<"Write stream to file by pasing an ofstream object\n open streamfile.txt to check"<< endl;
    write_something(myfile);
    cout <<"Write to stringstream object and reading using str() method \n";
    write_something(streamstring);
    cout << streamstring.str() << endl;
    cout <<"Finaly using cout as input argument to function\n";
    write_something(cout);
    cout << "End: Showcasing stream inheritance\n";

}