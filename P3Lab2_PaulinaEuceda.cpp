#include <iostream>
#include <cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main(int argc, char** argv) {
	int numeroRandom;
	srand((unsigned)time(0));
	numeroRandom = rand() % 100;
	
	cout << numeroRandom;
	
	return 0;
}
