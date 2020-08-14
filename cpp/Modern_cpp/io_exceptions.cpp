#include "io_exceptions.hpp"

using namespace std;

void with_io_exceptions(ios& io)
{   
    /// enables exceptions
    io.exceptions(ios_base::badbit | ios_base::failbit);
} // end of with_io_exceptions

void io_exceptions()
{

    ifstream infile;
    with_io_exceptions(infile);
    try
    {   
        cout << "Start: showcasing  io_exception \n";
        infile.open("non_existingfile");
    }
    catch(ios_base::failure & e)
    {
        cout <<"File opening error " << e.what() << " error code " << e.code()  << endl;
        cout << "End: showcasing  io_exception \n";
       
    }
    
}