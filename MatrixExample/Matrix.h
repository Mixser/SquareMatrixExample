#pragma once
#include <ostream>
#include <istream>

class SquareMatrix
{
private:
	double * matrix_;
	unsigned int size_;

private:
    void resizeMemory(const int new_size);
	void freeMemory();
    
public:
	SquareMatrix();
    SquareMatrix(const int size);
	SquareMatrix(const SquareMatrix &);
	~SquareMatrix();


    SquareMatrix operator*(const SquareMatrix & matrix) const;
    SquareMatrix operator*(const double alfa) const;
    SquareMatrix operator/(const double alfa) const;
    SquareMatrix operator+(const SquareMatrix & matrix) const;
    SquareMatrix operator-(const SquareMatrix & matrix) const;

    friend SquareMatrix operator*(const double alfa, const SquareMatrix & matrix);
    friend SquareMatrix operator/(const double alfa, const SquareMatrix & matrix);

    double * operator[](const int index);

    double get(const int i, const int j) const;
    void set(const int i, const int j, const double value);
	unsigned int getSize() const;

	friend std::ostream & operator<<(std::ostream &, const SquareMatrix &);
	friend std::istream & operator>>(std::istream &, SquareMatrix &);
};

