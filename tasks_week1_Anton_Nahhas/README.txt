tasks_week1_Anton_Nahhas

author details:
-name: Anton Nahhas
-email: antonna@edu.hac.ac.il
-ID: 315248708

exercise goal: build a class similar to std::vector using operator overloading, class functions and special c-tors

the class includes:

members: 
-m_size // the size of the vector (how many values is it holding)
-m_capacity // overall memory capacity
-m_array // the values of the vectors are stored in an array 

functions:
-data() //returns pointer to first cell in vector
- empty() //checks if the vector is empty
- push_back(const int&) //adds value to the end of the vector
- resize(std::size_t) //resizes vector to desired size and fill with 0's if needed
- resize(std::size_t, const int&) //resizes vector to desired size and fill with given value if needed
- clear() //clears the vector not affecting the capacity
- swap(Vector&) //swaps two vectors with one another
- pop_back() // removes last value from the vector
- begin() //returns the first cell
- end() //returns the last cell
- insert(iterator, const int& ) // inserts a given value to the desired cell
- erase(iterator) // deletes a desired cell

overloaded operators:
-operator= //copy assignment or move assignment
-operator== //equality operator
-operator<< // output operator
-operator[] // get data inside of a certain cell operator

getters/setters:
-getSize //gets the size 
-getCapacity //gets the capacity

c-tors and d-tors:
-normal c-tor
-move c-tor
-copy c-tor


additional notes:
for the move constructor and assignment operator had to add noexcept since vs asked me to, 
since no exceptions were thrown,, 
