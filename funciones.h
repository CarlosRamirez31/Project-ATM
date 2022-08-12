#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;


struct Cuentas{
	string nombre;
	string nCuenta;
	string contra;	
	int saldo;
}User[5];

void nUsuario();
void login();
void menu();
void menuRetiro();
void retirar(int);
int depositar(int);
void usuarios(Cuentas[]);

char opcion;
int deposito, Numero;

void login(){
	string nCuenta, contra;
	char NIP;
	
	do{
		fflush(stdin);
		
		cout << "\tBienvenido!" << endl;
		nUsuario();
		cout << "\nIngrese su numero de cuenta: "; cin >> nCuenta;
		cout << "\nIngrese su NIP: ";
		
	
		NIP = getch();
		contra = "";      
		while(NIP != 13){
			if(NIP != 8){
				contra.push_back(NIP);
				cout << "*";	
			}
			else{
				if(contra.length() > 0){
					cout << "\b \b";	
					contra = contra.substr(0, contra.length() - 1);
				}
			}	
			NIP = getch();
		}
		
		if((nCuenta == User[Numero].nCuenta) && (contra == User[Numero].contra)){
			menu();
		}
		else{
			cout << "\nPor favor compruebe que su numero de cuenta y NIP esten bien "<< endl;
			system("pause");
		}
		system("cls");
	}
	while((nCuenta != User[Numero].nCuenta) && (contra != User[Numero].contra));
}

void nUsuario(){
	int i;
	string nombreU;
	bool band = false;
	
	usuarios(User);
	
	do{
		cout << "\nDigite su nombre de usuario: "; getline(cin,nombreU);
		for(i=0;i<5;i++){
			if(nombreU == User[i].nombre){
				Numero = i;
				band = true;
			}
		}
		
		if(band == false){
			cout << "\tNombre de usuario incorrecto" << endl;
			system("pause");
			system("cls");
			cout << "\tBienvenido!" << endl;
		}
	}
	while(band == false);
}

void menu(){
	do{
		system("cls");
		cout << "\tMenu principal" << endl;
		cout << "1 - Ver mi saldo" << endl;
		cout << "2 - retirar efectivo" << endl;
		cout << "3 - Depositar fondos" << endl;
		cout << "4 - Salir" << endl;
		cout << "Escriba una opcion: "; cin >> opcion;
		
		switch(opcion){
			case '1':
				system("cls");
				cout << "Su saldo es de " << User[Numero].saldo << " pesos" << endl;
				system("pause"); break;
			case '2':
				system("cls");
				menuRetiro();
				break;
			case '3':
				system("cls");
				cout << "Digite el monto que quiere depositar: "; cin >> deposito;
				depositar(deposito);
				cout << "\tEl deposito se ha completado correctamente " << endl;
				system("pause"); break;
			case '4':
				system("cls");
				cout << "Gracias por utilizar el menu\n\n";
				system("pause"); break;
			default:
				system("cls");
				cout << "\tSeleccione una de las opciones que se muestra en el menu\n\n";
				system("pause"); 
		}
	}
	while(opcion != '4');
}


void usuarios(Cuentas U[]){
	U[0].nombre = "Beambollow";
	U[0].nCuenta = "12345";
	U[0].contra = "54321";
	U[0].saldo = 2500;
	
	U[1].nombre = "Manuel";
	U[1].nCuenta = "2020";
	U[1].contra = "54321";
	U[1].saldo = 500;
	
	U[2].nombre = "Jose";
	U[2].nCuenta = "2003";
	U[2].contra = "54321";
	U[2].saldo = 1000;
	
	U[3].nombre = "Patricia";
	U[3].nCuenta = "2021";
	U[3].contra = "54321";
	U[3].saldo = 2200;
	
	U[4].nombre = "Ana";
	U[4].nCuenta = "1995";
	U[4].contra = "54321";
	U[4].saldo = 5000;
}


void menuRetiro(){
	do{
		cout << "Menu de retiro" << endl;
		cout << "\t1 - $20 \t 4 - $100" << endl;
		cout << "\t2 - $40 \t 5 - $200" << endl;
		cout << "\t3 - $60 \t 6 - Cancelar Transaccion" << endl;
		cout << "Elija un monto de retiro: "; cin >> opcion;
		
		switch(opcion){
			case '1':
				system("cls");
				retirar(20);
				system("pause"); break;
			case '2':
				system("cls");
				retirar(40);
				system("pause"); break;
			case '3':
				system("cls");
				retirar(60);
				system("pause"); break;
			case '4':
				system("cls");
				retirar(100);
				system("pause"); break;
			case '5':
				system("cls");
				retirar(200);
				system("pause"); break;
			case '6':
				system("cls");
				cout << "\tCargando menu pricipal" << endl;
				system("pause"); break;
			default:
				system("cls");
				cout << "\tSeleccione una de las opciones que se muestra en el menu\n\n" << endl;
				system("pause"); break;
		}
		system("cls");
	}
	while(opcion != '6');
}

void retirar(int n){
	if(n > User[Numero].saldo){
		cout << "No tienes saldo suficiente para retirar" << endl;
		cout << "\tSaldo disponible en su cuenta " << User[Numero].saldo << " pesos"<< endl;
	}
	else{
		User[Numero].saldo -= n;
		cout << "\tEl retiro se ha completado correctamente" << endl;
	}
}

int depositar(int n){
	return User[Numero].saldo += n;
}
