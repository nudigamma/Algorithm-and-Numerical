/** this program is takes the concepts in the modrern C++ for scientific and engineers 
 * and simulate the content for quick studies **/
//** BUG : if selection is entered as a string it breaks the program */ 
#include "modern_main.hpp" 

using namespace std;
void print_new_lines()
{
    cout << "\n\n\n";
}
int main(int argc, char** argv)
{
   
    int selection = 0;
   

    while(true)
    {
        cout << "Please make a selection for the following\n";
        cout << "Type 999 to exit\n";
        cout << "Type 1 to show case the conditional operator ? : \n";
        cout << "Type 2 to show case non-narrowing initialization \"{}\", C++ keywords \"auto\"  and \"constexper\" \n";
        cout << "Type 3 to show case passing by value and passing by ref \n";
        cout << "Type 4 to demonstate simple for loop"
        cin >> selection;
        //cout << type_info(selection) << endl;
        switch(selection)
        {   
            case 1:
                conditional_op();
                print_new_lines();
            break;

            case 2:
                braces_initialization();
                print_new_lines();
            break;

            case 3:
                pass_by_ref_val();
                print_new_lines();
            break;

            case 999:
                cout <<"Exiting \n";
            return 0;
        default:
            cout << "Not programmed yet, use other codes\n";
            break;
        } // exits switch

    } // exits loop
} // exits main