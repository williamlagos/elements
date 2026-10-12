/*
 * This file is part of elements project.
 * 
 * Copyright (C) 2009-2011 William Oliveira de Lagos <william.lagos@icloud.com>
 *
 * Elements is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Elements is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with elements. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include<string>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

template<typename T>
class Matrix{
private:
	vector<vector<T>> base;
	int numOfCols;
	int numOfRows;
public:
	Matrix(int size = 0);
	Matrix(int cols, int rows, const T& initialValue = T());
	int getCols() const;
	int getRows() const;
	void createCol();
	void createRow();
	void clean();
	void set(int col, int row, const T& val);
	T get(int col, int row) const;
	void insert(T*);
	void remove(T*);
	void search(string);
};

typedef Matrix<int> IntMatrix;
typedef Matrix<float> FloatMatrix;
typedef Matrix<double> DoubleMatrix;
typedef Matrix<bool> BoolMatrix;

#endif /* MATRIX_H */
