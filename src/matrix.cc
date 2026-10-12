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

#include <matrix.h>

template<typename T>
Matrix<T>::Matrix(int size)
	: numOfCols(size), numOfRows(size), base(size, vector<T>(size))
{
}

template<typename T>
Matrix<T>::Matrix(int cols, int rows, const T& initialValue)
	: numOfCols(cols), numOfRows(rows), base(cols, vector<T>(rows, initialValue))
{
}

template<typename T>
int Matrix<T>::getCols() const
{
	return this->numOfCols;
}

template<typename T>
int Matrix<T>::getRows() const
{
	return this->numOfRows;
}

template<typename T>
void Matrix<T>::createRow()
{
	this->numOfRows += 1;
	for(auto &col : this->base){
		col.resize(this->numOfRows);
	}
}

template<typename T>
void Matrix<T>::createCol()
{
	this->base.emplace_back(this->numOfRows);
	this->numOfCols += 1;
}

template<typename T>
void Matrix<T>::clean()
{
	this->base.clear();
	this->numOfCols = 0;
	this->numOfRows = 0;
}

template<typename T>
void Matrix<T>::set(int col, int row, const T& val)
{
	if(col >= 0 && col < this->numOfCols && row >= 0 && row < this->numOfRows){
		this->base[col][row] = val;
	}
}

template<typename T>
T Matrix<T>::get(int col, int row) const
{
	if(col >= 0 && col < this->numOfCols && row >= 0 && row < this->numOfRows){
		return this->base[col][row];
	}
	return T();
}

template<typename T>
void Matrix<T>::insert(T* item)
{
	if(!item) return;
	this->createCol();
	for(int i = 0; i < this->numOfRows; i++){
		this->base[this->numOfCols - 1][i] = (*item);
		item++;
	}
}

template<typename T>
void Matrix<T>::remove(T*)
{
}

template<typename T>
void Matrix<T>::search(string)
{
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<bool>;
template class Matrix<char>;
template class Matrix<unsigned char>;
