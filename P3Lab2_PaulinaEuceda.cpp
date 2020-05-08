#include <iostream>
#include <cstdlib>
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

bool encontrarMCD(int, int);

void imprimirArray(int arre[], int tamano);

int jugar(int array[], int tamano);

int main(int argc, char** argv) {
	int numeroRandom, opcion;
	srand((unsigned)time(0));
	numeroRandom = rand() % 100;
	
	while(opcion != 4){
	
		cout<<"		Menu"<<endl
			<<"1.- Ejercicio 1"<<endl
			<<"2.- Ejercicio 2"<<endl
			<<"3.- Ejercicio 3"<<endl
			<<"4.- Salir"<<endl
			<<"Ingrese la opcion que desea: ";	
		cin >> opcion;
		
		switch(opcion){
			case 1:{
				int numeroIngresado, cantMCD=0;
				bool respuestaMetodo;
				cout << "Ingrese un numero entero positivo: ";
				cin >> numeroIngresado;
				while(numeroIngresado < 0){
					cout << "No es positivo. Ingrese un numero entero positivo: ";
					cin >> numeroIngresado;
				}
				
				for(int i = 1; i<=numeroIngresado; i++){
					respuestaMetodo = encontrarMCD(numeroIngresado,i);
					if(respuestaMetodo == true){
						cantMCD++;
					}
				}
				 cout << "phi(" << numeroIngresado << ")=" << cantMCD <<endl;
				 cout << endl;
				break;
			}
			case 2:{
					
				break;
			}	
			case 3:{
				int numPar;
				
				cout << "Ingrese un numero par: ";
				cin >> numPar;
				
				while(numPar % 2 == 1){
					cout << "No es un numero par. Ingrese un numero par: ";
					cin >> numPar;
				}
				
				int arrayRanNum[numPar]={};
				for(int i = 1; i<=numPar; i++){
					numeroRandom = -50 + rand() % (50+1 - (-50));
					arrayRanNum[i]= numeroRandom;
				}
				
				jugar(arrayRanNum, numPar);
				
				
				imprimirArray(arrayRanNum, numPar);
				
				break;
			}	
			case 4:{
				cout<<"Bye"<<endl;
				break;
			}
		}
	}
	
	return 0;
}


bool encontrarMCD(int numerador, int denominador){
	if(!(denominador>numerador) && denominador!=0){
		int residuo = numerador % denominador;
		encontrarMCD(denominador,residuo);
		
	}else{
		if(numerador==1){
			return true;
		}else{
			return false;
		}
	}
	
}

void imprimirArray(int arre[], int tamano){
	for(int i=0; i<tamano; i++){
		cout << arre[i]<<" ";
	}
	cout << endl;
}

int jugar(int array[], int tamano){
	cout << "hola";
	
}
