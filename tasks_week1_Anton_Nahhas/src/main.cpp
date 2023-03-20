// tasks_week1_Anton_Nahhas.cpp : Defines the entry point for the application.
//
#include "Vector.h"

using namespace std;

int main()
{
	/*test block for move, copy constructors and move, copy assignment operators*/
	//Vector v1(4, 1);//create a vector
	//Vector v2(v1);// copy a vector
	//Vector v3(std::move(v1));// move a vector
	//Vector v5(4, 1);
	//Vector v4;
	//v4 = v2;
	//v4 = std::move(v5);
	//std::cout << v2 << std::endl << v3 << std::endl << v4;//will be printed
	//std::cout << v1 << std::endl << v5;//wont be printed, since they were moved...
	
	/*test block for push_back and resize class functions*/
	/*Vector v1(3);
	std::cout << v1;
	std::cout << endl;
	v1.push_back(2);
	std::cout << v1;
	std::cout << endl;
	v1.resize(9);
	std::cout << v1;
	std::cout << endl;*/

	/*test block for data function*/
	/*Vector v1(5, 1);
	const int* p = v1.data();
	for (int i = 0; i < v1.getSize(); ++i) {
		std::cout << p[i] << " ";
	}
	*/

	/*test block for clear function, note that the capacity is left unchanged*/
	/*Vector v1(6, 6);
	std::cout << v1;
	std::cout << endl;
	v1.clear();
	std::cout << v1;
	std::cout << endl;*/

	/*test block for swap between two vectors function*/
	/*Vector v1(2, 1);
	Vector v2(5, 6);
	std::cout << v1 << std::endl << v2 << std::endl << "------------------" << std::endl;
	v1.swap(v2);
	std::cout << v1 << std::endl << v2 << std::endl << "------------------" << std::endl;*/

	/*test block for pop_back() function*/
	/*Vector v1(5, 6);
	std::cout << v1 << endl;
	v1.pop_back();
	std::cout << v1 << endl;
	v1.pop_back();
	std::cout << v1 << endl;
	v1.pop_back();
	std::cout << v1 << endl;
	v1.pop_back();
	std::cout << v1 << endl;*/

	/*test block for == operator*/
	//Vector v1(2, 2);
	//Vector v2(2, 2);
	//std::cout << (v1 == v2) << std::endl;
	//Vector v3(2, 4);
	//std::cout << (v1 == v3) << std::endl;

	/*test block for insert function*/
	/*Vector v1(3, 100);
	auto it = v1.begin();
	std::cout << v1 << std::endl;
	v1.insert(it, 5);
	std::cout << v1 << std::endl;*/

	/*test block for erase function*/
	/*Vector v1(6, 6);
	auto it = v1.begin();
	std::cout << v1 << std::endl;
	v1.erase(it);
	std::cout << v1 << std::endl;
	v1.erase(it);
	std::cout << v1 << std::endl;
	v1.erase(it);
	std::cout << v1 << std::endl;
	v1.erase(it);
	std::cout << v1 << std::endl;
	v1.erase(it);
	std::cout << v1 << std::endl;*/

	return 0;
}
//std::cout<<endl;