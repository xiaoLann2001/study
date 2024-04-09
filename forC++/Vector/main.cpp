#include <iostream>
using namespace std;

#include "Vector.h"

int main()
{
    Vector v1(1, 1, 1);
    Vector v2(2 ,3 ,4);
    Vector result;
    double result1;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    
    result = v1 + v2;
    cout << "v1 + v2  = " << result << endl;

    result = v1 - v2;
    cout << "v1 - v2  = " << result << endl;

    result1 = v1 * v2;
    cout << "v1 * v2  = " << result1 << endl;

    result = v1 + 100;
    cout << "v1 + 100 = " << result <<  endl;

    result = v1 - 100;
    cout << "v1 - 100  = "<< result << endl;

    return 0;
}