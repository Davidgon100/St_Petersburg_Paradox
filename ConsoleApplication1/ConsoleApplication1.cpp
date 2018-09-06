// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;


int coin_flip() {
	/* This function returns either 0 or 1. 
	Here 0 is a coin flip of tails and heads is 1*/
	return rand() % 2;
}


double sp() {
	/*This function is 1 Saint Petersburg game.
	The coin keeps being flipped until heads is landed.
	Then 2^n is returned, where n is the number of flips
	that it took to get heads.*/
	int n = 1; 
	int flip = 0;
	while(flip == 0) {
		n++;
		flip = coin_flip();
	}
	return pow(2,n);
}

double buffon(int n) {
	double summation = 0;
	for (int j = 0; j < 2048; j++) {
		summation += sp();
	}
	return summation / 2048;
}

int main() {
	srand(time(NULL));
	int games[] = { 1000,2048,5000,10000,50000,100000,500000,1000000 };
	double expected_values[8];
	int k = 0;
	for (double n:games) {
		double summation = 0;
		for (int i = 0; i <= n; i++) {
			summation += sp();
		}
		expected_values[k] = summation / n;
		k++;
	}
	cout << "The expected values of the experiment for\nn = 1000, 2048, 5000, 10000, 50000, 100000, 500000, 1000000 \nrespectively are as follows:" << endl;
	ofstream outFile;
	outFile.open("expected_vals.txt");
	int array_index=0;
	for (double expected_value : expected_values) {
		cout << "for n = " << games[array_index] << " E[X] = " << expected_value << endl;
		outFile << games[array_index] << "," << expected_value << endl;
		array_index++;
	}
	//outFile.close();
	//return 0;
}

/*
int main(){ 
	srand(time(NULL));
	int i = 0;
	double summation;
	double sums_average;
	int trials = 1000;
	while(i < trials){
		summation = 0;
		sums_average=0;
		for (int j = 0; j < 2048; j++) {
			summation += sp();
		}
		summation = summation; // 2048;
		sums_average += summation;
		
		i++;
	}
	cout << sums_average/trials << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
*/