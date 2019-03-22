#include <stdio.h>
#include <stdlib.h>

void printmenu() {
	/*
	Function for printing the menu of the application
	output: the printed menu
	*/
	printf("1. Generate the first n prime numbers\n");
	printf("2. Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime\n");
	printf("3. Decompose a given natural numbers is its prime factors\n");
	printf("4. Exit\n");
}

int prime(x) {
	/*
	Function for verifying if a number is prime
	input: x - a number
	output: 1 - if the number is prime , 0 - if the number is not prime
	*/
	int i;
	for (i = 2; i <= x / 2; i++)
		if (x%i == 0) return 0;
	return 1;
}

void readVector(int *v) {
	/*
	Function for reading a vector of numbers from the keyboard
	input: v - the empty vector
	output: v - the vector of numbers
	*/
	int i = 0;
	scanf("%d", &v[0]);
	while (v[i] != 0) {
		i++;
		scanf("%d", &v[i]);
	}
}

int relativelyPrime(a, b) {
	/*
	Function for verifying if two given numbers are relatively prime
	input: a,b - two given numbers
	output: 1 - if the numbers are relatively prime , 0 - if the numbers are not relatively prime
	*/
	if (a == 0 || b == 0) return 0;
	while (a != b) {
		if (a>b) a = a - b;
		else b = b - a;
	}
	if (a == 1) return 1;
	return 0;
}

int readOption(char option) {
	/*
		Function that reads from the keyboard a string and validates it as a option
		input: option - char type variable
		output: option - if the string read form the keyboard is a valid option , "Invalid choice!" - otherwise
	*/
	scanf("%s", &option);
	while (option != '1' && option != '2' && option != '3' && option != '4') {
		printf("Invalid choice!\n");
		scanf("%s", &option);
	}
	return option;
}

int main(){
	/*
		The main programm
	*/
	int n, keepAlive=1;
	char option=' ';
	while (keepAlive) {
		printmenu();
		option = readOption(option);
		if (option == '1') {
			printf("Enter a number:\n");
			scanf("%d", &n);
			int k = 0, nr = 2;
			while (k<n) {
				if (prime(nr)) {
					k++;
					printf("%d ", nr);
				}
				nr++;
			}
			printf("\n");
		}
		else
			if (option == '2') {
				printf("Enter a vector of numbers:\n");
				int v[100], i = 0, j = 0, d = 0, dmax = 0, imax, jmax, nv = 0, ok = 1;
				readVector(&v);
				while (v[i] != 0) {
					while (relativelyPrime(v[i], v[i + 1]) == 0 && v[i] != 0)
						i++;
					if (v[i] == 0 && ok == 1) break; //that means that no 2 consecutive numbers are relatively prime
					if (v[i] == 0) break;
					j = i;
					while (relativelyPrime(v[j], v[j + 1]) == 1 && v[j] != 0)
						j++;
					if (v[j] == 0) break;
					d = j - i;
					if (d>dmax) {
						dmax = d;
						imax = i;
						jmax = j;
					}
					i = j + 1;
					ok++;
				}
				if (ok == 1) printf("there is no such sequence!\n");
				else {
					for (i = imax; i <= jmax; i++) printf("%d ", v[i]);
					printf("\n");
				}
			}
		if (option == '3') {
			printf("Enter a number:\n");
			scanf("%d", &n);
			int divizor = 2, putere = 0;
			while (n > 1) {
				putere = 0;
				while (n%divizor == 0) {
					putere++;
					n = n / divizor;
				}
				if (putere > 0) printf("%d to the power of %d\n", divizor, putere);
				divizor++;
			}
		}

		if (option == '4') {
			keepAlive = 0;
			printf("exit :) . . .\n");
			}
		
	}
	return 0;
}