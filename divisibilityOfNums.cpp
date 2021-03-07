/*
* @Author: Alpha Kaba
* @Since: 03-07-2021
* @version: 1.0
*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void reverseArray(int arr[], int arrLength);
void swapInt(int& i1, int& i2);

int main() {
	try {
		ifstream inFile("input.txt");
		if (!inFile.good())
			throw string("Fail to open input.txt");
		ofstream outFile("ouput.txt");
		if (!outFile)
			throw string("Failure opening output.txt");

		int num;
		while(inFile >> num) {
			outFile << num << " : ";
			// 'arr' will contains all divisible numbers from 'num'
			int arr[(int) sqrt(num)];
			int n=0; //n will keep track of the index of 'arr'
			bool divisible = false;
			for (int i=2; i<=sqrt(num); i++) {
				if(num%i == 0) {
					divisible = true;
					
					if(num/i!=i)
						arr[n++] = num/i;
						
					outFile << i ;
				
					if(n!=0)
						outFile << ", ";
					else
						outFile << endl;
				}
				
				// if no divisor is found, print 'None'
				if (!divisible && i==(int) sqrt(num))
					outFile << "None\n";
				
				// if i == sqrt(num), means we have all divisors of num in 'arr'
				if(i == (int) sqrt(num) ) {
					reverseArray(arr, n);
				
					//printing out the reversed arrat=y
					for(int i=0; i<n; i++) {
						if(i<n-1)
							outFile << arr[i] << ", ";
						else
							outFile << arr[i] << endl;
					}
				}
			}
		}
	} catch (string message) {
		cerr << message << endl;
		exit(1);
	}
}

//The below function reverse a descending ordered-array to ascending one
void reverseArray(int arr[], int n){
	for(int i=0; i<n/2; i++)
		swapInt(arr[i], arr[n-i-1]);
}

//swapInt swaps two integers given their references.
void swapInt(int& i1, int& i2) {
	int temp = i2;
	i2 = i1;
	i1 = temp;
}
