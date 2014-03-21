#include "Matrix.h"


SquareMatrix::SquareMatrix() : matrix_(NULL), size_(0)
{
}


SquareMatrix::SquareMatrix(const int size) : matrix_(NULL), size_(size)
{
    resizeMemory(size_);
}


SquareMatrix::SquareMatrix(const SquareMatrix & rhs) : matrix_(NULL), size_(0)
{
    resizeMemory(rhs.size_);
    std::copy(rhs.matrix_, rhs.matrix_ + (rhs.size_ * rhs.size_), matrix_);
}


SquareMatrix::~SquareMatrix()
{
    freeMemory();
}


void SquareMatrix::resizeMemory(const int new_size)
{
    freeMemory();
    size_ = new_size;
    matrix_ = new double[new_size * new_size];
    std::fill(matrix_, matrix_ + (new_size*new_size), 0.0);
}


void SquareMatrix::freeMemory()
{
    if (matrix_ != NULL)
    {
        delete[] matrix_;
        size_ = 0;
        matrix_ = NULL;
    }
}


double * SquareMatrix::operator[](const int index)
{
    return matrix_ + (index * getSize());
}


double SquareMatrix::get(const int i, const int j) const
{
    return matrix_[i*getSize() + j];
}

void SquareMatrix::set(const int i, const int j, const double value)
{
    matrix_[i*getSize() + j] = value;
}


SquareMatrix SquareMatrix::operator*(const SquareMatrix & matrix) const
{
    if (getSize() != matrix.getSize())
        throw "Matrix must be equal size!!!";

    SquareMatrix result(getSize());
    for (unsigned int i = 0; i < result.getSize(); i++)
        for (unsigned int j = 0; j < result.getSize(); j++)
        {
            double temp = 0;
            for (unsigned int k = 0; k < getSize(); k++)
                temp += this->get(i, k) * matrix.get(k, j);
            result[i][j] = temp;
        }
    return result;
}


SquareMatrix SquareMatrix::operator+(const SquareMatrix & rhs)const
{
    if (getSize() != rhs.getSize())
        throw "Matrix must be equal size!!!";

    SquareMatrix result(*this);
    for (unsigned int i = 0; i < result.getSize(); i++)
        for (unsigned int j = 0; j < result.getSize(); j++)
            result[i][j] += rhs.get(i, j);
    return result;
}

SquareMatrix SquareMatrix::operator-(const SquareMatrix & rhs)const
{
    return (*this) + (-1) * rhs;
}


SquareMatrix SquareMatrix::operator*(const double alfa) const
{
    SquareMatrix result(*this);
    for (unsigned int i = 0; i < result.getSize(); i++)
        for (unsigned int j = 0; j < result.getSize(); j++)
            result[i][j] *= alfa;
    return result;
}


SquareMatrix SquareMatrix::operator/(const double alfa) const
{
    return (1/alfa) * (*this);
}


unsigned int SquareMatrix::getSize() const
{
    return size_;
}


SquareMatrix operator*(const double alfa, const SquareMatrix & matrix)
{
    return matrix * alfa;
}


SquareMatrix operator/(const double alfa, const SquareMatrix & matrix)
{
    return matrix / alfa;
}


std::ostream & operator<<(std::ostream & out, const SquareMatrix & rhs)
{
    for (unsigned int i = 0; i < rhs.getSize(); i++){
        for (unsigned int j = 0; j < rhs.getSize(); j++)
            out << rhs.get(i, j) << " ";
        out << std::endl;
    }
    return out;
}


std::istream & operator>>(std::istream & in, SquareMatrix & rhs)
{
    unsigned int size = 0;
    in >> size;
    rhs.resizeMemory(size);
    for (unsigned int i = 0; i < size; i++)
        for (unsigned int j = 0; j < size; j++)
            in >> rhs[i][j];
    return in;
}

