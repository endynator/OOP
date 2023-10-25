#include "../headers/individual_work2.h"
#include <iostream>

using namespace std;

void work2() {
	dynamic_array<uint16_t> arr(3); 
	arr.newData(11, 7, 26, 53, 6, 1, 9);
	cout << "Initial array: "; arr.display();
	arr.resize(5);
	dynamic_array<uint16_t> arr2(arr); 
	cout << "Copy array: "; arr2.display();
	cout << "Resized: "; arr.display();
	
	cout << "Min: " << arr.min() << "; Max: " << arr.max() << endl;
	arr.sort();
	cout << "Sort initial: "; arr.display();
	cout << "Copy array: "; arr2.display();
}