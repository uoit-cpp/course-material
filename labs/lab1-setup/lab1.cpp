#include "average.h"
#include <iostream>
using namespace std;

int main()
{
	float a, b, c;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;
	cout << "Enter c: "; cin >> c;
	
	cout << "Average of a, b and c is " << average3(a, b, c) << endl;
	
	// Part 2
	float arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float ave, sd;
	average(arr, 5, ave, sd);
	cout << "Average of arr is " << ave << endl;
	cout << "SD of arr is " << sd << endl;

	return 0;
}
