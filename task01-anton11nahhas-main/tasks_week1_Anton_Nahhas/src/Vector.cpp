#pragma once
#include "Vector.h"


//--------------------------------------------------------------------------------

/*constructor that receives a size and a value, the size is the size of the vector,
and the value will fill the vector. if a value was not given then fill 0's*/
Vector::Vector(std::size_t size, int value) : m_size(size), m_capacity(size){
	/*std::cout << "created" << std::endl;*/
	m_array = new int[m_capacity];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = value;
	}

}

//--------------------------------------------------------------------------------
/*a copy constructpr, receives another vector and is copied to the lvalue vector*/
Vector::Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_size) {
	/*std::cout << "copied" << std::endl;*/
	m_array = new int[other.m_size];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}

}

//--------------------------------------------------------------------------------

/*a move constructor receives a temporary r value and is moved to the lvalue*/
Vector::Vector(Vector&& other) noexcept : m_size(other.m_size), m_capacity(other.m_size), m_array(other.m_array) {
	/*std::cout << "moved" << std::endl;*/

	other.m_size = 0;
	other.m_capacity = 0;
	other.m_array = nullptr;

}

//--------------------------------------------------------------------------------
/*copy assignment operator, this is the lvalue and the other is the rvalue, save the lvalue in lvalue,
by copying each value found in rvalue onto lvalue*/
Vector& Vector::operator=(const Vector& other) {
	
	/*std::cout << "copy operator" << std::endl;*/
	if (this != &other)// if lhs == rhs return this object.
	{
		if (m_size != other.m_size)//if lhs size != rhs size make new array with new size.
		{
			m_size = other.m_size;
			int* newArray = new int[m_size];
			delete[] m_array;
			m_array = newArray;
		}
		for (int i = 0; i < m_size; i++)
			m_array[i] = other.m_array[i];//copy rhs to lhs
	}
	return *this;
}

//--------------------------------------------------------------------------------
/*move assignment operator, receives a temporary rvalue other and moves it to lvalue*/
Vector& Vector::operator=(Vector&& other)noexcept{
	/*std::cout << "move operator" << std::endl;*/
	if (this != &other)// if lhs == rhs return this object.
	{
		delete[] m_array;
		if (m_size != other.m_size)//if lhs size != rhs size make new array with new size.
		{	
			m_size = other.m_size;
			m_capacity = other.m_size;
		}
		m_array = other.m_array;
		other.m_size = 0;
		other.m_capacity = 0;
		other.m_array = nullptr;
	}
	return *this;
}

//--------------------------------------------------------------------------------
/*this function receives a value adds a cell at the end and pushes the value there,
the function does not return*/
void Vector::push_back(const int& value) {
	
	std::size_t tempSize = m_size +  1;
	if (tempSize >= m_capacity ) {
		resize(tempSize, value);
	}

	m_array[m_size - 1] = value;

}

//--------------------------------------------------------------------------------
/*this function resizes the vector to the desired count, if count is bigger than curr
size then resize to new size and fill with 0's if the vouns is smaller than the curr
size then only show the new size values, the function does not return */
void Vector::resize(std::size_t count) {
	resize(count, 0);
	
}

//--------------------------------------------------------------------------------
/*this function resizes the vector to the desired count and value, if the count is bigger
than the current size then change to new size and fill with the value provided, if the
count is smaller than the current size then only show the first count elements*/
void Vector::resize(std::size_t count, const int& value) {
	std::size_t tempSize = m_size;

	if (m_capacity < count) {
		while (m_capacity < count) {
			if (m_capacity <= 128) {
				if (m_capacity == 0) { m_capacity = 2; }
				else {
					m_capacity *= 2;
				}
			}
			else { m_capacity *= 1.5; }
		}
	}
	if (m_size > count) {
		m_size = count;
		int* newArray = new int[m_size];
		for (int i = 0; i < m_size; i++) {
			newArray[i] = m_array[i];
		}
		delete[] m_array;
		m_array = std::move(newArray);
	}
	else {
		m_size = count;
		int* newArray = new int[m_size];
		for (std::size_t i = 0; i < tempSize; i++) {
			newArray[i] = m_array[i];
		}
		for (std::size_t i = tempSize; i < count; i++) {
			newArray[i] = value;
		}
		delete[] m_array;
		m_array = std::move(newArray);
	}
}

//--------------------------------------------------------------------------------
/*this function returns a pointer that points on the first cell of the vector, does not
do anything if the vector is empty*/
int* Vector::data() {
	if (m_size != 0) {
		return &m_array[0];
	}
}

//--------------------------------------------------------------------------------
/*this function clears the vector, meaning resizing the vector to 0 and emptying
its values however it does not affect the capacity of the vector, the function 
does not return anything*/
void Vector::clear() {
	m_size = 0;
	m_array = 0;
}

//--------------------------------------------------------------------------------
/*this function removes the last value in the vector, the function does not return
anything*/
void Vector::pop_back() {
	if (m_size != 0) {
		m_size--;
	}
}

//--------------------------------------------------------------------------------
/*this operator checks if the left hand side is equal to the right hand side, it 
returns true if they are equal and false otherwise, it does so by checking first 
if the sizes of both sides are equal and then check for each cell in both sides 
if equal otherwise returns false*/
bool operator==(const Vector& lhs, const Vector& rhs) {
	if (lhs.getSize() == rhs.getSize()) {
		for (int i = 0; i < lhs.getSize(); i++) {
			if (lhs[i] != rhs[i]) {
				return false;
			}
			return true;
		}
	}
	return false;
}

//--------------------------------------------------------------------------------
/*this function receives an iterator position and a valye, the value is inserted 
before the position given, and returns the pointer that points on the position,
it does so by looping until the position is found.*/
int* Vector::insert(iterator pos, const int& val) {
	int counter = 0,
		index = 0;
	iterator beg = begin();
	std::size_t newSize = m_size + 1;
	int* newArray = new int[m_size];
	if (newSize >= m_capacity) {
		resize(newSize);
	}
	else {
		m_size = newSize;
	}

	while (index < m_size) {
		if (beg != pos) {
			newArray[index] = m_array[counter];
			counter++;
		}
		else {
			newArray[index] = val;
		}
		index++;
		++beg;
	}
	delete[] m_array;
	m_array = std::move(newArray);


	return pos;

}

//--------------------------------------------------------------------------------
/*this function receives an iterator, and its goal to delete the element on that 
position that the iterator is pointing at, returns the pointer that the pos is
pointing at. It does so by searching for the position required and deleting it*/
int* Vector::erase(iterator pos) {
	iterator beg = begin();
	int* newArray = new int[m_size--];
	int index = 0;

	while (index < m_size) {
		if (beg != pos) {
			newArray[index] = *beg;
			index++;
		}
		++beg;
	}

	delete[] m_array;
	m_array = std::move(newArray);
	return pos;

}

//--------------------------------------------------------------------------------
/*this function receives lvalue and swaps the current lvalue with the provided one, 
this is done by saving a temporary vector, swaping all the data from one side to the
other.*/
void Vector::swap(Vector& other) {
	Vector tempVector(*this);
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_array = other.m_array;

	other.m_size = tempVector.m_size;
	other.m_capacity = tempVector.m_capacity;
	other.m_array = tempVector.m_array;
}

//--------------------------------------------------------------------------------
/*this operator is overloaded in order to print out the members of the vector*/
std::ostream& operator<<(std::ostream& output, const Vector& vector)
{
	for (int i = 0; i < vector.getSize(); i++)
		output << vector[i] << " ";

	return output;
}