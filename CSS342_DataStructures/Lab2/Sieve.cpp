//----------------------------------------Sieve.cpp--------------------------------------------
//Gregory Asher				CSC 342					
//Date of creation: 01-22-2016
//Last modified: 01-25-2016
//-----------------------------------------------
//Purpose: The purpose of this program is to pick out the prime numbers between 2 and a given user's input
// additionally this program counts the number of times the innermost loop is run, and displays it at the end.
//------------------------------------------------
//This program required use of the Sieve or Eratosthenes algorithm.
//------------------------------------------------


#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int sieve(int n, vector<int> &primes) {


	int cost = 0;

	// 1. Implement array initialization so that every value is prime except 0 and 1
	//create boolean array with length n+1
	bool array[n + 1];
	//set entire array to be true
	//NOTE: This means that initially we're considering that EVERY NUMBER IS PRIME
	//UNLESS otherwise determined
	memset(array, true, sizeof(array));
	// 2. Implement Sieve of Eratosthenes algorithm to find prime numbers
	//start at 2, because that's what we're told to do, also 0 can't be prime.
	//Definition of prime: "Divisible by only itself and 1"; cannot divide by zero.
	//square p, check to make sure so long as that value is less than input parameters
	//increment by 1 each loop
	for (int p = 2; p*p <= n; p++)
	{
		// If array[p] is not changed, then it is a prime
		//initially this will be true, but by squaring p, we instantly discover an integer divisible by
		//not only itself, but also p
		if (array[p] == true)
		{ 
			//Set the aforementioned multiples of p to be false right now
			for (int i = p * 2; i <= n; i += p) {
				array[i] = false;
				//incrementing cost here, as this is deepest level for statement
				cost += 1;
			}
		}
	}
	// 3. Push back the prime numbers into primes (parameter)
	for (int p = 2; p <= n; p++)
		if (array[p]) {
			primes.push_back(p);
		}

	return cost; //return the cost of running this loops.
}
//THE MAIN WAS PROVIDED 
int main() {
	int n = 0;

	cout << "Enter n ";
	cin >> n;

	char printOption = 'n';
	cout << "print all primes (y|n)? ";
	cin >> printOption;

	//

	for (int i = 2; i <= n; i++) {

		vector<int> primes;
		int cost = sieve(i, primes);

		cout << "primes[1.." << i << "] took " << cost
			<< " sweeping operations" << endl;

		if (printOption == 'y') {
			cout << "all primes = ";
			for (int j = 0; j < primes.size(); j++)
				cout << primes[j] << " ";
			cout << endl;

		}

		cerr << i << " " << cost << endl;

	}

	return 0;
}