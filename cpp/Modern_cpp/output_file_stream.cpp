#include "output_file_stream.hpp"

using namespace std;
void output_file_stream(string filename)
{
    /** if need explicit opening we can do as follows 
     * ofstream square;
     * square.open(filename);
     * some logic;
     * square.close();
    */
    cout << "Start: Showcasing open file to write\n";
    ofstream square(filename);
    for (int i = 0 ; i <= 10 ; ++i )
    {
        square << i << endl;
    }
    cout << "End: Showcasing open file to write" << endl << "     check square.txt file";
}
