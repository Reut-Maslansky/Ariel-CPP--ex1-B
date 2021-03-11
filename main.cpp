#include "snowman.cpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    cout << "Hey!" << endl;
    cout << "We're going to draw a snowman together!" << endl;
    cout << "lets start!" << endl;
    cout << "Please enter 8 digits from 1-4 and we will print a contact of your choice." << endl;
    cout << "To stop the program, enter '0'" << endl;

    long num = 1;
    while (num > 0)
    {
        cin >> num;

        try
        {
            cout << ariel::snowman(num) << endl;
        }
        catch (exception &ex)
        {
            if(num!=0)
            cout << "   caught exception: " << ex.what() << endl;
            else cout<<"exit"<<endl;
        }
    }
    return 0;
}