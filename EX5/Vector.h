//
// Created by danielBentov on 12/01/2023.
//

#ifndef EX5_VECTOR_H
#define EX5_VECTOR_H
#include <iostream>
using namespace std;

class Vector {
private:

    double const ERROR = -999;
    double* elements;
    int size;


public:
    explicit Vector(int n);
    Vector(const double a[], int n);
    Vector(const Vector &v);
    int getSize();
    Vector operator=(const Vector& v);
    double operator[](int ind);
    Vector operator+(double d);
    friend Vector operator+(double d , Vector v);
    Vector operator*(double d);
    friend Vector operator*(double d, Vector& v);
    Vector operator*(const Vector& v);
    bool operator==( Vector& v);
    friend std::ostream& operator<<(std::ostream& out, Vector& v);
    double dot(Vector& v);
    ~Vector();
};


#endif //EX5_VECTOR_H
