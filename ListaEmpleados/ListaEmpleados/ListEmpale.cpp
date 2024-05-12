#include<iostream>
using namespace std;

int Menu();
void Altas();
void Consultas();
//int Cambios();
//int Bajas();
int verificaExiste();
void Reportes();

typedef struct Empleados {
	int clave;
	char nombre[80];
	struct Empleados* sig;
};

Empleados* Trabajo = NULL, * Inicio = NULL, * Final = NULL;
Empleados* Lugar = NULL, * apIzq = NULL, * apDer = NULL;


int main() {
	int op = 0;
	do {
		op = Menu();
		switch (op)
		{
		case 1: {Altas(); break; }
		case 2: {Consultas(); break; }
			  //case 3: {Cambios(); break; }
			  //case 4: {Bajas(); break; }
		case 5: {Reportes(); break; }
		case 6: { break; }
		}
	} while (op != 6);

}


int Menu() {
	int op = 0;
	do {
		system("cls");
		cout << "\n\t\a Opciones";
		cout << "\n\t 1. Altas \n\t 2. Consultas \n\t 3. Cambios \n\t 4. Bajas \n\t 5. Reportes \n\t 6. Salir";
		cin >> op;
	} while (op < 1 || op>6);
	return op;
}

void Altas() {
	int existe = 0;
	int clave = 0;
	char op = ' ';
	do {
		system("cls");
		cout << "\n\t\a Alta de Empleados";
		cout << "\n\t Ingrese la clave: "; cin >> clave;
		existe = verificaExiste(clave);  //Manda a llamar a la funcion para verificar si existe el empleado por medio de la clave.
		if (existe <= 0) {
			Trabajo = (Empleados*)malloc(sizeof(Empleados));
			Trabajo->clave = clave;
			cout << "\n\t Ingrese el nombre: ";
			cin >> Trabajo->nombre;
			Trabajo->sig = NULL;
			if (Inicio == NULL) {
				Inicio = Trabajo;
			}
			else {
				Final->sig = Trabajo;
			}
			Final = Trabajo;
			Trabajo = NULL;
		}
		else {
			cout << "\n\t Ya existe. ";
		}
		cout << "\n\t\a Desea agregar mas clientes? s/n"; cin >> op;

	} while (op == 's');

}

void Consultas() {
	int existe = 0;
	int clave = 0;
	char op = ' ';
	do {
		system("cls");
		cout << "\n\t\a Consultas";
		cout << "\n\t Ingrese la clave: "; cin >> clave;
		existe = verificaExiste(clave);  //Manda a llamar a la funcion para verificar si existe el empleado por medio de la clave.
		if (existe > 0) {  //Si es mayor a cero, significa q encontró al empleado.
			cout << Lugar->clave << "\n\t Nombre: " << Lugar->nombre;
		}
		else {
			cout << "\n\t No existe. ";
		}
		cout << "\n\t\a Desea agregar mas clientes? s/n"; cin >> op;

	} while (op == 's');

}


/*int Cambios(int clave) {
	int nuevaclave;
	char op = ' ';
	do {
		system("cls");
		cout << "\n\t\a Ingrese la clave del empleado a modificar: ";
		cin >> clave;
		cout << "\n\t\a Ingrese la nueva clave del empleado: ";
		cin >> nuevaclave;
		Trabajo = Inicio;
		while (Trabajo != NULL) {
			if (Trabajo->clave == clave) {
				Trabajo->clave = nuevaclave;
				return 1;
				cout << "El cambio fue realizado.";
			}
			Trabajo = Trabajo->sig;

		}return 0;

		cout << "Desea cambiar otro empleado? s/n";
		cin >> op;

	} while (op == 's');

}

int Bajas(int clave) {
	char op = ' ';
	do {
		system("cls");
		cout << "\n\t\a Ingrese la clave que desee eliminar: ";
		cin >> clave;
		Trabajo = Inicio;
		while (Trabajo != NULL) {
			if (Trabajo->clave == clave) {
				if (Trabajo = Inicio) {
					Inicio = Inicio->sig;
				}
				else {
					Final->sig = Trabajo->sig;
				}
				delete(Trabajo);
				return 1;
				cout << "El empelado fue eliminado.";
			}
			Final = Trabajo;
			Trabajo = Trabajo->sig;

		}return 0;

		cout << "Desea cambiar otro empleado? s/n";
		cin >> op;

	} while (op == 's');

}*/


void Reportes() {
	char op = ' ';
	do {
		system("cls");
		cout << "\n\t\t Reportes";
		Trabajo = Inicio;
		while (Trabajo != NULL) {
			cout << "\n\t" << Trabajo->clave << " " << Trabajo->nombre;
			Trabajo = Trabajo->sig;
		}
		cout << "\n\tOtro Reporte  s/n?";
		cin >> op;

	} while (op == 's');

}

int verificaExiste(int clave) {
	int existe = 0;
	Trabajo = Inicio;
	while (Trabajo != NULL) {
		if (Trabajo->clave == clave) {
			existe = 1;
			Lugar = Trabajo;
			break;
		}
		Trabajo = Trabajo->sig;
	}
	return existe;
}