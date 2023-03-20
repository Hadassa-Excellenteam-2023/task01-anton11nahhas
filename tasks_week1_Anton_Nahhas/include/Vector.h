#pragma once
#include <iostream>

class Vector {
public:

	using iterator = int*;

	Vector(const Vector&);// copy constructor
	Vector(std::size_t size = 0, int value = 0);// constructor 
	Vector(Vector&&)noexcept; // move constructor

	Vector& operator=(const Vector&);//copy assignment
	Vector& operator=(Vector&&)noexcept;//move assignment 

	int& operator[](std::size_t index) { return m_array[index]; }
	const int& operator[](std::size_t index) const { return m_array[index]; }

	std::size_t getSize() const { return m_size; }
	std::size_t getCapacity() const { return m_size; }

	int* data();
	bool empty() { return (m_size == 0); }
	void push_back(const int&);
	void resize(std::size_t);
	void resize(std::size_t, const int&);
	void clear();
	void swap(Vector&);
	void pop_back();

	iterator begin() { return m_array; }
	iterator end() { return m_array + getSize(); }
	iterator insert(iterator, const int& );
	iterator erase(iterator);

private:
	int* m_array;
	std::size_t m_size;
	std::size_t m_capacity;
};

bool operator==(const Vector& , const Vector& rhs);
std::ostream& operator<<(std::ostream&, const Vector&);