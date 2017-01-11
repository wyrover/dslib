/*
 *
 *  Zigzag traversal of a matrix
 *
 *
 *
 */

#ifndef __MATRIX_H
#define __MATRIX_H

#include "dslib.h"

using namespace std;

template <class T>
class Matrix {
    private:
        vector<T> _values;
        int _m, _n;
    public:
        Matrix(int m, int n): _m(m), _n(n) {
            _values.resize(_m);
            for (auto&i : _values) {
                i.resize(_n);
            }
        }

        Matrix(Matrix const& copy);

        //Copy constructor
        Matrix operator=(Matrix const& copy);
        //Assign a value like matrix(2,3) =5. Since this is in LHS, we return a reference
        T& operator()(size_t i, size_t j);
        //Read or print a value
        T operator()(size_t i, size_t j) const;
        //friend functions are declared inline to prevent forward declaration
        friend ostream& operator<<(ostream& in, Matrix<T> const& output) {
            return in;
        }


};

template <class T>
T Matrix<T>:: operator()(size_t i, size_t j) const
{
    if (i > _m) {
        throw out_of_range("Matrix rows out of bounds");
    }
    if (j > _n) {
        throw out_of_range("Matrix cols out of bounds");
    }

    return _values[ i*_m + j];


}


template <class T>
T& Matrix<T>:: operator()(size_t i, size_t j)
{




}


#endif





















