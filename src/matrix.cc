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
{
	this->numOfCols = size;
	this->numOfRows = size;
}

template<typename T>
void Matrix<T>::createRow()
{
	typename vector<vector<T>*>::iterator it;
	for(it = this->base.begin(); it != this->base.end(); it++){
		(*it)->resize(numOfRows+1);
	}
}
template<typename T>
vector<T> Matrix<T>::createCol()
{
	vector<T> col;
	this->base.push_back(&col);
	this->numOfCols += 1;
	return col;
}
template<typename T>
void Matrix<T>::clean()
{
	
}
template<typename T>
void Matrix<T>::insert(T* item)
{
	vector<T> column = this->createCol();
	for(int i = 0; i < this->numOfRows; i++){
		column.push_back((*item));
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
template class Matrix<bool>;
