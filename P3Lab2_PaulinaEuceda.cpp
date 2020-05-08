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
					int numeroPas;
					cout << "Ingrese un numero: ";
					cin >> numeroPas;
					
					int arrayPas[numeroPas]={};
					int arrayAux[numeroPas]={};
					
					for(int i=0; i< numeroPas; i++){
						//if(i<=1){
							arrayPas[0] = 1;
							arrayAux[0] = 1;
							arrayPas[i] = 1;
							arrayAux[i] = 1;
						
						for(int j=0; j< i; j++){
							
								/*if((j==0) || j==(i-1)){
									arrayPas[j] = 1;
									arrayAux[j] = 1;
								}else{*/
									int suma = arrayAux[j]+arrayAux[j-1];\
									arrayPas[j] = suma;
								//}
								
							
						}
						for(int k=0; k< i; k++){
							arrayAux[k] = arrayPas[k];
						}
						imprimirArray(arrayPas, numeroPas);
					}
					
				break;
			}	
			case 3:{
				int numPar;
				cout << "**BIENVENIDO**"<< endl;
				
				cout << "Ingrese un numero par: ";
				cin >> numPar;
				
				while(numPar % 2 == 1){
					cout << "No es un numero par. Ingrese un numero par: ";
					cin >> numPar;
				}
				
				int arrayRanNum[numPar]={};
				int arrayAux[numPar] = {};
				for(int i = 0; i<=numPar; i++){
					numeroRandom = -50 + rand() % (50+1 - (-50));
					arrayRanNum[i]= numeroRandom;
					arrayAux[i]= numeroRandom;
				}
				
				jugar(arrayRanNum, numPar);
				
				
				
				imprimirArray(arrayAux, numPar);
				
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
	
	int rondas=1;
	int posJug1, posJug2, posicion, puntosJ1=0, puntosJ2=0;
	
	cout << "¡A jugar!"<< endl;
	cout << endl;
	int lugares = tamano-1;
	
	for(int i = 0; i < tamano; i++){
		if(i%2==0){
			cout << "J1 escoge [0-" << lugares << "]: ";
			cin >> posicion;
		}else{
			cout << "J2 escoge [0-" << lugares << "]: ";
			cin >> posicion;
		}
		
		while(posicion > tamano){
			cout << "¡Esa posicion no existe. Escoja otra: "<< endl;
			cin >> posicion;
		}
		
		while(array[posicion] == 55){
			cout << "¡Ese valor ya fue tomado. Escoja otro valor: "<< endl;
			cin >> posicion;
		}
		
		if(i%2==0){
			puntosJ1= puntosJ1 + array[posicion];
			cout << "Obtuvo: " << array[posicion] << endl;
			array[posicion] = 55;
		}
		else{
			puntosJ2= puntosJ2 +array[posicion];
			
			cout << "Obtuvo: " << array[posicion] << endl;
			array[posicion] = 55;
			cout << endl;
			
			cout << "Ronda" << rondas << " - [PTS J1: " << puntosJ1 << " <-> PTS J2: " << puntosJ2 << "] " << endl;
			rondas++;
		}
		
	}
	
	cout<<endl;
	cout << "Final - [PTS J1: " << puntosJ1 << " <-> PTS J2: " << puntosJ2 << "] " << endl;
	cout<<endl;
	
	if(puntosJ1 < puntosJ2){
		cout << "Gana J2" << endl;
	}else if(puntosJ1 > puntosJ2) {
		cout << "Gana J1" << endl;
	}else{
		cout << "Empate" << endl;
	}
	cout<<endl;
	
	cout << "El arreglo usado fue:  ";
	
}
