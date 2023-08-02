//
// Created by danielBentov on 12/01/2023.
//

#include "Vector.h"
//The constructor will produce a vector of size n with all elements 0.
Vector::Vector(int n) {
    size = n;
    elements = new double [size];
    for (int i = 0; i < size; ++i) {
        elements[i] = 0;
    }
}
//The constructor accepts as a parameter an array of double and its size (n)
// and will create a vector of size n whose members are the members of array a.
Vector::Vector(const double a[], int n) {
    size = n;
    elements = new double[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = a[i];
    }

}
// copy constructor
Vector::Vector(const Vector &v) {
    size = v.size;
    elements = new double [size];
    for (int i = 0; i < size; ++i) {
        elements[i] = v.elements[i];
    }
}
// gets the size
int Vector::getSize() {
    return size;
}
//The operator '=' will copy the 'v' data to 'this'
Vector Vector::operator=( const Vector& v) {
    size = v.size;
    delete [] elements;
    elements = new double [size];
    for (int i = 0; i < size; ++i) {
        elements[i] = v.elements[i];
    }
        return *this ;

}
//The function will receive an index as a parameter and return the member found in the ind index or ERROR if the index is invalid
    double Vector::operator[](int ind) {
        if (ind < size)
            return elements[ind];

        return ERROR;
    }
//Add num 'd' to the vector and return a new vector with the result.
    Vector Vector::operator+(double d) {

    Vector v1 (*this);

        for (int i = 0; i < this->size; ++i) {
           v1.elements[i]  += d;
        }
        return v1;
    }
//Add num 'd' to the vector and return a new vector with the result.
Vector operator+(double d, Vector v) {
    Vector v1 (v+d);
    return  v1;


}
//  multiply with num 'd' on a vector and return a new vector
Vector Vector::operator*(double d) {

    Vector v1(this->elements, this->size);
    for (int i = 0; i < this->size; ++i) {
        v1.elements[i] = this->elements[i] * d;
    }
        return v1;
    }

//  multiply with num 'd' on a vector and return a new vector
Vector operator*(double d, Vector &v) {
    return Vector(v*d);
}
//Multiplies two vectors and returns a new vector with the result
Vector Vector::operator*(const Vector &v) {
    Vector v1(this->elements, this->size);
    for (int i = 0; i < this->size; ++i) {
        v1.elements[i] = this->elements[i] * v.elements[i];
        return v1;
    }
}
// Compare two vectors
bool Vector::operator==(Vector &v) {
        if(this->size != v.size)
            return false;
    for (int i = 0; i < v.size; ++i) {
        if (this->elements[i] != v.elements[i])
                return false;}
    return true;
}
// Print to 'out' the vector
std::ostream &operator<<(std::ostream &out, Vector &v) {
    cout << "[";
    for (int i = 0; i < v.size-1; ++i) {
        cout << v.elements[i] <<", ";
    }
    cout << v.elements[v.size-1] << "]";
    return  out;
}
//Perform a scalar multiplication between two vectors.
double Vector::dot(Vector &v) {
    double sum =0;
    for (int i = 0; i < v.size; ++i) {
        sum+= this->elements[i]*v.elements[i];

    }
    return sum;
}
// destructor
Vector::~Vector() {
    delete [] elements;

}
