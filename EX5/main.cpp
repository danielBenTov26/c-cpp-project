#include <iostream>
#include "Vector.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
using namespace std;

int main() {
    Vector a(4);
    double arr[] ={2.1, 3.5, 6.2, 4.8};
    Vector b(arr, 4);
    Vector c = b * 2;
    cout<<"A:  " << a<<endl
    << "b:    " << b<<endl
    << "C:    " <<c<<endl
    <<"c[3]:  "<<c[4]<<endl;

    a=c;
    cout << " A=C:   " << a << endl;
    Vector v1  = b + 5;
    cout << "v1 = b+5  " << v1 << endl;
    Vector f1 (4);
    Vector f (f1);

    f = 5 + v1;
    cout << "f = 5+v1  " << f << endl;

    f = 2 * c;
    cout << "f = 2*c  " << f << endl;
   double r = b.dot(b);
    cout << r<< endl;
    if(a==c)
        cout<< "a==c :)"<<endl;
    else
        cout << "a != c :("<< endl;

    if(a==v1)
        cout<< "a==v1 :)"<< endl;
    else
        cout << "a != v1 :("<< endl;
    cout<< f.getSize()<<endl;

}

#pragma clang diagnostic pop