#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
void menu();
void agregarq();
void modificar();
void eliminar();
void vigentes();
void limpiar();
void agarchivo();
void lecturarch();
struct videojuegos {
	char ID[50];
	char anio[50];
	char preciochar[50];
}estructura[100];
float precio[100], impuesto[100], preciototal[100];
char op, agregar, op1, gg[50];
int i = 0, IDint[100], anioint[100], y = 0;
string name[100], clasi[100], cara[100], des[100], gen[100];
bool band = true;
void agarchivo() {
	ofstream archivo;
	int il = 0;
	archivo.open("gameztop.txt", ios::out);
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	while (estructura[il].ID[0] != NULL) {
		archivo << estructura[il].ID << endl
			<< name[il] << endl
			<< estructura[il].anio << endl
			<< clasi[il] << endl
			<< cara[il] << endl
			<< des[il] << endl
			<< gen[il] << endl
			<< estructura[il].preciochar << endl;
		il++;
	}
	archivo.close();
}//ocupa detalles
void lecturarch() {
	ifstream archivo;
	ofstream primerarchivo;
	string linea;
	int il = 0;
	archivo.open("gameztop.txt",ios::in);
	if (archivo.fail() && estructura[0].ID[0] == NULL) {
		primerarchivo.open("gameztop.txt", ios::out);
	}
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	while (!archivo.eof()) {
		getline(archivo, linea);
		strcpy_s(estructura[il].ID, linea.c_str());
		getline(archivo, linea);
		name[il] = linea;
		getline(archivo, linea);
		strcpy_s(estructura[il].anio, linea.c_str());
		getline(archivo, linea);
		clasi[il] = linea;
		getline(archivo, linea);
		cara[il] = linea;
		getline(archivo, linea);
		des[il] = linea;
		getline(archivo, linea);
		gen[il] = linea;
		getline(archivo, linea);
		strcpy_s(estructura[il].preciochar, linea.c_str());
		y = il;
		il++;
	}
	for (int it = 0; it <= y; it++) {
		precio[it] = atof(estructura[it].preciochar);
		impuesto[it] = precio[it] * .16;
		preciototal[it] = precio[it] + impuesto[it];
	}
}//ocupa detalles
void menu() {
	do {
		system("cls");
		cout << "Tienda de videojuegos" << endl;
		cout << "Menu" << endl;
		cout << "1. Agregar articulo" << endl;
		cout << "2. Modificar articulo" << endl;
		cout << "3. Eliminar articulo" << endl;
		cout << "4. Lista de articulos vigentes" << endl;
		cout << "5. Limpiar pantalla" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese el numero de la opcion que desee realizar: ";
		op = _getch();

		switch (op) {
		case 49:
			agregarq();
			if (i >= 100) {
				cout << "Ya no puede dar de alta más videojuegos" << endl;
				break;
			}
			if (agregar != 49) {
				break;
			}
		case 50:
			modificar();
			break;
		case 51:
			eliminar();
			break;
		case 52:
			vigentes();
			break;
		case 53:
			limpiar();
			break;
		default:
			if (op == 54) {
				break;
			}
			cout << "El valor que usted ingreso no corresponde a ninguna de las acciones del menu, por favor intente otra vez" << endl;
			system("pause");
			break;
		}

	} while (op != 54);
}
void agregarq() {
	
	do {
		if (y < 99) {
			for (int it = 0; it <= 99; it++) {
				if (estructura[it].ID[0] == NULL) {
					i = it;
					it = 100;
				}
			}

			system("cls");
			for (int q = 0; q < 50; q++) {
				estructura[i].ID[q] = NULL;
			}
			for (int x = i; x <= i; x++) {
				cout << "Ingrese el ID del articulo: ";
				cin.getline(estructura[i].ID, 50, '\n');
				for (int v = 0; v <= 99; v++) {
					if (v != i && estructura[i].ID[0] != NULL) {
						while (strcmp(estructura[i].ID, estructura[v].ID) == 0) {
							cout << "El ID ingresado ya existe, por favor ingrese otro: ";
							cin.getline(estructura[i].ID, 50, '\n');
							if (strcmp(estructura[i].ID, estructura[v].ID) != 0) {
								x = i;
							}
							v = -1;
						}
					}
				}
				for (int j = 0; j < 50; j++) {
					if (estructura[i].ID[j] < 48 || estructura[i].ID[j]>57) {
						if (estructura[i].ID[0] == NULL) {
							cout << "No ha ingresado un valor, por favor ingrese un valor" << estructura[i].ID << endl;
							j = 50;
							x = x - 1;
						}
						if (estructura[i].ID[j] == 0) {

						}
						else {
							cout << "los caracteres que usted ingreso no coinciden con la lista de numeros enteros, por favor vuelva a intentarlo" << endl;
							for (int p = 0; p <= 50; p++) {
								estructura[i].ID[p] = NULL;
							}
							x = x - 1;
							j = 50;
							system("pause");
						}
					}
				}
			}
			cout << "Ingrese el nombre del articulo: ";
			getline(cin, name[i]);
			for (int q = 0; q < 50; q++) {
				estructura[i].anio[q] = NULL;
			}
			for (int x = i; x <= i; x++) {
				cout << "Ingrese el anio del articulo: ";
				cin.getline(estructura[i].anio, 50, '\n');
				for (int j = 0; j < 50; j++) {
					if (estructura[i].anio[j] < 48 || estructura[i].anio[j]>57) {
						if (estructura[i].anio[0] == NULL) {
							cout << "No ha ingresado un valor, por favor ingrese un valor" << endl;
							j = 50;
							x = x - 1;
						}
						if (estructura[i].anio[j] == 0) {

						}
						else {
							cout << "los caracteres que usted ingreso no coinciden con la lista de numeros enteros, por favor vuelva a intentarlo" << endl;
							for (int p = 0; p < 50; p++) {
								estructura[i].anio[p] = NULL;
							}
							x = x - 1;
							j = 50;
							system("pause");
						}
					}
				}
			}
			cout << "Ingrese la clasificacion: ";
			getline(cin, clasi[i]);
			cout << "Ingrese caracteristicas del videojuego: ";
			getline(cin, cara[i]);
			cout << "Ingrese la descripcion del videojuego: ";
			getline(cin, des[i]);
			cout << "Ingrese el genero: ";
			getline(cin, gen[i]);
			for (int q = 0; q < 50; q++) {
				estructura[i].preciochar[q] = NULL;
			}
			for (int x = i; x <= i; x++) {
				cout << "Ingrese el precio unitario: ";
				cin.getline(estructura[i].preciochar, 50, '\n');
				for (int j = 0; j < 50; j++) {
					if (estructura[i].preciochar[j] < 48 || estructura[i].preciochar[j]>57) {
						if (estructura[i].preciochar[0] == NULL) {
							cout << "No ha ingresado un valor, por favor ingrese un valor" << endl;
							j = 50;
							x = x - 1;
						}
						if (estructura[i].preciochar[j] == 0) {

						}
						else {
							cout << "los caracteres que usted ingreso no coinciden con la lista de numeros enteros, por favor vuelva a intentarlo" << endl;
							for (int p = 0; p <= 50; p++) {
								estructura[i].preciochar[p] = NULL;
							}
							x = x - 1;
							j = 50;
							system("pause");
						}
					}
				}
			}
			precio[i] = atof(estructura[i].preciochar);
			impuesto[i] = precio[i] * .16;
			preciototal[i] = precio[i] + impuesto[i];
			cout << "El impuesto del producto es: " << impuesto[i] << endl;
			cout << "El precio total es: " << precio[i] + precio[i] * .16 << endl;
			cout << "Si desea agregar un articulo presione 1, sino presione cualquier numero: ";
			agregar = _getch();
			i++;

		}
		else {
		i = y;
        }
		
	} while (agregar == 49 && i < 99);
}
void modificar() {
	system("cls");
	char b[50];
	cout << "Ingrese el ID del videojuego que desee modificar: ";
	cin.getline(b, 50, '\n');
	for (int z = 0; z <= 99; z++) {
		if (strcmp(estructura[z].ID, b) != 0) {
			if (z == 99) {
				cout << "El ID que usted ingreso no existe, ingrese otro valor: " << endl;
				for (int u = 0; u < 50; u++) {
					b[u] = NULL;
				}
				cin.getline(b, 50, '\n');
				z = -1;
				system("pause");
			}

		}
		else {
			z = 101;
		}



	}
	for (int j = 0; j <= 99; j++) {
		char newfloat[50];
		char newID[50], newanio[50];
		double newdouble;
		string newstring;
		if (strcmp(estructura[j].ID, b) == 0 && estructura[j].ID[0] != 0) {
			cout << "1. Modificar ID" << endl;
			cout << "2. Modificar nombre" << endl;
			cout << "3. Modificar anio de lanzamiento" << endl;
			cout << "4. Modificar la clasificacion" << endl;
			cout << "5. Modificar caracteristicas del videojuego" << endl;
			cout << "6 .Modificar la descripcion del videojuego" << endl;
			cout << "7. Modificar el genero" << endl;
			cout << "8. Modificar el precio unitario" << endl;
			cout << "Ingrese el numero de la opcion que desee realizar: ";
			op1 = _getch();
			switch (op1) {
			case 49:
				for (int x = j; x <= j; x++) {
					cout << "Cual quiere que sea el nuevo ID? ";
					for (int p = 0; p < 50; p++) {
						estructura[j].ID[p] = NULL;
					}
					cin.getline(estructura[j].ID, 50, '\n');
					for (int v = 0; v <= 99; v++) {
						if (v != j && estructura[j].ID[0] != NULL) {
							while (strcmp(estructura[j].ID, estructura[v].ID) == 0) {
								cout << "El ID ingresado ya existe, por favor ingrese otro: ";
								cin.getline(estructura[j].ID, 50, '\n');
								if (strcmp(estructura[j].ID, estructura[v].ID) != 0) {
									x = i;
								}
								v = -1;
							}
						}
					}
					for (int w = 0; w < 50; w++) {
						if (estructura[j].ID[w] < 48 || estructura[j].ID[w]>57) {
							if (estructura[j].ID[0] == NULL) {
								cout << "No ha ingresado un valor, por favor ingrese un valor" << endl;
								w = 50;
								x = x - 1;
							}
							if (estructura[j].ID[w] == 0) {

							}
							else {
								cout << "los caracteres que usted ingreso no coinciden con la lista de numeros enteros, por favor vuelva a intentarlo" << endl;
								for (int p = 0; p < 50; p++) {
									estructura[j].ID[p] = NULL;
								}
								x = x - 1;
								w = 50;
								system("pause");
							}
						}
					}
				}
				cout << "El nuevo ID es: " << estructura[j].ID << endl;
				band = false;
				system("pause");
				break;
			case 50:
				cout << "Cual quiere que sea el nombre? ";
				getline(cin, newstring);
				name[j] = newstring;
				cout << "El nuevo nombre de su videojuego es: " << name[j] << endl;
				band = false;
				system("pause");
				break;
			case 51:
				for (int x = j; x <= j; x++) {
					cout << "Cual quiere que sea el nuevo anio de lanzamiento? ";
					for (int p = 0; p < 50; p++) {
						estructura[j].anio[p] = NULL;
					}
					cin.getline(estructura[j].anio, 50, '\n');
					for (int w = 0; w < 50; w++) {
						if (estructura[j].anio[w] < 48 || estructura[j].anio[w]>57) {
							if (estructura[j].anio[0] == NULL) {
								cout << "No ha ingresado un valor, por favor ingrese un valor" << endl;
								w = 50;
								x = x - 1;
							}
							if (estructura[j].anio[w] == 0) {

							}
							else {
								cout << "los caracteres que usted ingreso no coinciden con la lista de numeros enteros, por favor vuelva a intentarlo" << endl;
								for (int p = 0; p < 50; p++) {
									estructura[j].anio[p] = NULL;
								}
								x = x - 1;
								w = 50;
								system("pause");
							}
						}
					}
				}
				cout << "El nuevo anio de lanzamiento es: " << estructura[j].anio << endl;
				band = false;
				system("pause");
				break;
			case 52:
				cout << "Cual quiere que sea la clasificacion? ";
				getline(cin, newstring);
				clasi[j] = newstring;
				cout << "La nueva clasificacion de su videojuego es: " << clasi[j] << endl;
				band = false;
				system("pause");
				break;
			case 53:
				cout << "Cual quiere que sean las nuevas caracteristicas? ";
				getline(cin, newstring);
				cara[j] = newstring;
				cout << "Las nuevas caracteristicas de su videojuego es: " << cara[j] << endl;
				band = false;
				system("pause");
				break;
			case 54:
				cout << "Cual quiere que sea la nueva descripcion? ";
				getline(cin, newstring);
				des[j] = newstring;
				cout << "Las nuevas caracteristicas de su videojuego es: " << des[j] << endl;
				band = false;
				system("pause");
			case 55:
				cout << "Cual quiere que sea el nuevo genero? ";
				getline(cin, newstring);
				gen[j] = newstring;
				cout << "El nuevo genero de su videojuego es: " << gen[j] << endl;
				band = false;
				system("pause");
				break;
			case 56:
				for (int x = j; x <= j; x++) {
					cout << "Cual quiere que sea el nuevo precio unitario? ";
					for (int p = 0; p < 50; p++) {
						estructura[j].preciochar[p] = NULL;
					}
					precio[j] = 0;
					cin.getline(estructura[j].preciochar, 50, '\n');
					for (int w = 0; w < 50; w++) {
						if (estructura[j].preciochar[w] < 48 || estructura[j].preciochar[w]>57) {
							if (estructura[j].anio[0] == NULL) {
								cout << "No ha ingresado un valor, por favor ingrese un valor" << endl;
								w = 50;
								x = x - 1;
							}
							if (estructura[j].preciochar[w] == 0) {

							}
							else {
								cout << "los caracteres que usted ingreso no coinciden con la lista de numeros enteros, por favor vuelva a intentarlo" << endl;
								for (int p = 0; p < 50; p++) {
									estructura[j].preciochar[p] = NULL;
								}
								x = x - 1;
								w = 50;
								system("pause");
							}
						}
					}
				}
				precio[j] = atof(estructura[j].preciochar);
				cout << "El nuevo precio de su videojuego es: " << precio[j] << endl;
				impuesto[j] = precio[j] * .16;
				preciototal[j] = impuesto[j] + precio[j];
				cout << "El nuevo impuesto de su videojuego es: " << impuesto[j] << endl;
				cout << "El nuevo precio total de su videojuego es: " << preciototal[j] << endl;
				band = false;
				system("pause");
				break;
			default:
				j = -1;
				break;
			}
			if (band = false) { j = 101; }


		}


	}
}
void eliminar() {
	bool bandera = true, bandamx = true;
	cout << "Ingrese el ID del articulo que desea eliminar: ";
	cin.getline(gg, 50, '\n');
	for (int it = 0; it <= 99; it++) {
		if (strcmp(gg, estructura[it].ID) == 0) {
			y = y - 1;
			for (it; it <= 99; it++) {
				if (it == 99) {
					for (int j = 0; j < 50; j++) {
						estructura[it].ID[j] = NULL;
					}
					name[it] = '\0';
					for (int j = 0; j < 50; j++) {
						estructura[it].anio[j] = NULL;
					}
					clasi[it] = '\0';
					cara[it] = '\0';
					des[it] = '\0';
					gen[it] = '\0';
					precio[it] = 0;
					impuesto[it] = 0;
					preciototal[it] = 0;
					bandamx = false;
				}
				if (estructura[it + 1].ID[0] != NULL && bandamx == true) {
					for (int p = 0; p < 50; p++) {
						estructura[it].ID[p] = 0;
					}
					strcpy_s(estructura[it].ID, estructura[it + 1].ID);
					for (int p = 0; p < 50; p++) {
						estructura[it].anio[p] = 0;
					}
					strcpy_s(estructura[it].anio, estructura[it + 1].anio);
				}
				else {
					if (estructura[it].ID[0] != NULL && bandamx == true) {
						for (int ap = 0; ap < 50; ap++) {
							estructura[it].ID[ap] = 0;
							estructura[it].anio[ap] = 0;
						}

					}
				}
				if (it != 99) {
					name[it] = name[it + 1];
					clasi[it] = clasi[it + 1];
					cara[it] = cara[it + 1];
					des[it] = des[it + 1];
					gen[it] = gen[it + 1];
					precio[it] = precio[it + 1];
					impuesto[it] = impuesto[it + 1];
					preciototal[it] = preciototal[it + 1];
					bandera = false;
				}

			}
		}
		if (bandera == true && it == 99) {
			cout << "El ID que ingresaste no existe, ingresa otro: ";
			for (int f = 0; f < 50; f++) {
				gg[f] = NULL;
			}
			cin.getline(gg, 50, '\n');
			it = -1;
		}
		if (bandera == false) {
			break;
		}
	}
}
void vigentes() {
	for (int it = 0; it <= 99; it++) {
		IDint[it] = atoi(estructura[it].ID);
		anioint[it] = atoi(estructura[it].anio);
	}
	struct {
		char genchar[50], clasichar[50];
	}cambio[100];
	for (int it = 0; it <= 99; it++) {
		strcpy_s(cambio[it].genchar, gen[it].c_str());
		strcpy_s(cambio[it].clasichar, clasi[it].c_str());
	}
	for (int it = 0; it < 100; it++) {
		for (int j = 0; j < 50; j++) {
			if (cambio[it].genchar[j] > 96 && cambio[it].genchar[j] < 123) {
				cambio[it].genchar[j] -= 32;
			}
		}
	}
	for (int it = 0; it < 100; it++) {
		for (int j = 0; j < 50; j++) {
			if (cambio[it].clasichar[j] > 96 && cambio[it].clasichar[j] < 123) {
				cambio[it].clasichar[j] -= 32;
			}
		}
	}
	char op2;
	cout << "De que forma quiere buscar el videojuego" << endl;
	cout << "1.Por ID" << endl;
	cout << "2.Por genero" << endl;
	cout << "3.Por clasificacion" << endl;
	cout << "Presione cualquier otra tecla para cancelar la busqueda" << endl;
	cout << "Presione el numero de la opcion que desee realizar: ";
	op2 = _getch();
	bool bander = true;
	switch (op2) {
	case 49:

		for (int j = 0; j <= 99; j++) {

			if (IDint[j] == 0) {
				for (int s = 0; s <= j - 1; s++) {
					cout << s + 1 << "-El ID del videojuego es: " << estructura[s].ID << endl;
					cout << "El nombre del videojuego es: " << name[s] << endl;
					cout << "El anio del videojuego es: " << estructura[s].anio << endl;
					cout << "La clasificacion del videojuego es: " << clasi[s] << endl;
					cout << "Las caracteristicas del videojuego es: " << cara[s] << endl;
					cout << "La descripcion del videojuego es: " << des[s] << endl;
					cout << "El genero del videojuego es: " << gen[s] << endl;
					cout << "El precio unitario del videojuego es: " << precio[s] << endl;
					cout << "El impuesto del videojuego es: " << impuesto[s] << endl;
					cout << "El precio total del videojuego es: " << preciototal[s] << endl;
					cout << "Presione cualquier tecla para ver el siguiente articulo; " << endl;
					system("pause");
					if (s == j - 1) {
						bander = false;
					}
				}
				if (bander == false) {
					j = 100;

				}
			}

		}
		break;
	case 50:
		char eve[50];
		cout << "Ingrese el genero que busca: ";
		cin.getline(eve, 50, '\n');
		for (int it = 0; it < 50; it++) {
			if (eve[it] > 96 && eve[it] < 123) {
				eve[it] -= 32;
			}

		}
		for (int it = 0; it <= 99; it++) {
			if (strcmp(eve, cambio[it].genchar) == 0 && cambio[it].genchar[0] != NULL) {
				cout << it + 1 << "-El ID del videojuego es: " << estructura[it].ID << endl;
				cout << "El nombre del videojuego es: " << name[it] << endl;
				cout << "El anio del videojuego es: " << estructura[it].anio << endl;
				cout << "La clasificacion del videojuego es: " << clasi[it] << endl;
				cout << "Las caracteristicas del videojuego es: " << cara[it] << endl;
				cout << "La descripcion del videojuego es: " << des[it] << endl;
				cout << "El genero del videojuego es: " << gen[it] << endl;
				cout << "El precio unitario del videojuego es: " << precio[it] << endl;
				cout << "El impuesto del videojuego es: " << impuesto[it] << endl;
				cout << "El precio total del videojuego es: " << preciototal[it] << endl;
				cout << "Presione cualquier tecla para ver el siguiente articulo; " << endl;
				system("pause");
			}
			else {
				if (it == 99) {
					cout << "no introdujo un valor existente" << endl;
				}
			}
		}
		break;
	case 51:
		char vicks[50];
		cout << "Ingrese la clasificacion que busca: ";
		cin.getline(vicks, 50, '\n');
		for (int it = 0; it < 50; it++) {
			if (vicks[it] > 96 && vicks[it] < 123) {
				vicks[it] -= 32;
			}

		}
		for (int it = 0; it <= 99; it++) {
			if (strcmp(vicks, cambio[it].clasichar) == 0 && cambio[it].clasichar[0] != NULL) {
				cout << it + 1 << "-El ID del videojuego es: " << estructura[it].ID << endl;
				cout << "El nombre del videojuego es: " << name[it] << endl;
				cout << "El anio del videojuego es: " << estructura[it].anio << endl;
				cout << "La clasificacion del videojuego es: " << clasi[it] << endl;
				cout << "Las caracteristicas del videojuego es: " << cara[it] << endl;
				cout << "La descripcion del videojuego es: " << des[it] << endl;
				cout << "El genero del videojuego es: " << gen[it] << endl;
				cout << "El precio unitario del videojuego es: " << precio[it] << endl;
				cout << "El impuesto del videojuego es: " << impuesto[it] << endl;
				cout << "El precio total del videojuego es: " << preciototal[it] << endl;
				cout << "Presione cualquier tecla para ver el siguiente articulo; " << endl;
				system("pause");
			}
			else {
				if (it == 99) {
					cout << "no introdujo un valor existente" << endl;
				}
			}
		}
		break;
	default:
		break;
	}





}
void limpiar() {
	system("cls");
}
void main() {
	
	lecturarch();
	menu();
	cout << "Usted ha salido exitosamente" << endl;
	agarchivo();
	system("pause");
}