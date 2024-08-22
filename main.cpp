#include<stdio.h>
#include<conio.h>
#include<string>
#include<windows.h>
#include<ctype.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);	
	
// --------------------------------------------------------------------------- estructuras
	
	char conti;
	int i, a, b;
	int num_viajeros = 0;
	const int max_viajeros = 1000;
	char ing;
	string id_viaj;
	int total = 0;
struct Viajero{
	
	string nombre;
	string id;
	string edad;
	string sexo;
	string nacionalidad;
	
}viajero[max_viajeros];

	
struct Ingreso{
	
	string lugar_ingreso;
	
}ingreso[max_viajeros];

struct Salida{
	
	string lugar_destino;
	
}salida[max_viajeros];

struct Fecha{
	
	string dia;
	string mes;
	string anio;
	
}fech[max_viajeros];

struct registros{
	
	string salida_entrada;
	
}registro[max_viajeros];
// --------------------------------------------------------------------------- Funciones

void gotoxy();
void cuadros();
void agregar();
void Menu();
// --------------------------------------------------------------------------- gotoxy

void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

// --------------------------------------------------------------------------- cuadros

void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}

// --------------------------------------------------------------------------- Ingresar viajero

void agregar(){
	
	system("cls");
	
	SetConsoleTextAttribute (hConsoleHandle, 7);
	
	cuadro(10,5,88,16);
	cuadro(40,2,62,4);
	
	SetConsoleTextAttribute (hConsoleHandle, 9);
	gotoxy(43,3); cout << "-AGREGAR VIAJERO-";
	
	SetConsoleTextAttribute (hConsoleHandle, 9);
	
	num_viajeros = num_viajeros + 1;
	
	SetConsoleTextAttribute (hConsoleHandle, 9);

	gotoxy(12,6); cout << "INGRESE LOS SIGUIENTES DATOS DEL VIAJERO";
	gotoxy(12,7); cout << "Nombre:";
	getline (cin, viajero[num_viajeros].nombre);
	
	gotoxy(12,8); cout << "Numero de id:";
	getline (cin, viajero[num_viajeros].id);
	
	gotoxy(12,9); cout << "Edad:";
	getline(cin, viajero[num_viajeros].edad);
	
	gotoxy(12,10); cout << "Sexo:";
	getline (cin, viajero[num_viajeros].sexo);
	
	gotoxy(12,11); cout << "Nacionalidad:";
	getline (cin, viajero[num_viajeros].nacionalidad);
	
	gotoxy(12,15); cout << "Desea ingresar otro viajero? S/N";
	conti=getch();	
		
	if(conti == 's' || conti == 'S'){
		agregar();
	}else{
		Menu();
	}
}

// --------------------------------------------------------------------------- registrar
void registrar(){
	
	system("cls");
	
	SetConsoleTextAttribute (hConsoleHandle, 7);
	
	cuadro(10,5,95,19);
	cuadro(40,2,75,4);
	
	SetConsoleTextAttribute (hConsoleHandle, 9);
	gotoxy(43,3); cout << "-REGISTRAR SALIDAS Y ENTRADAS-";
	
	SetConsoleTextAttribute (hConsoleHandle, 9);
	
	gotoxy(12,6); cout << "Desea registrar un ingreso = 1 o una salida = 2?: ";
	
	do{
	
	ing=getch();
	
	if(ing == '1'){
		
		gotoxy(12,7); cout << "Ingrese el id del viajero (debe de estar registrado previamente):";
		getline(cin, id_viaj);
		
		for(i = 0; i < (num_viajeros + 1); i++){
        if(id_viaj == viajero[i].id){
	        b = 1;
		    a = i;
	    	break;
	    }else{
		    b = 0;
	    }
	}
 
	    if(b == 1){
	    	gotoxy(12,8); cout << "DATOS DEL VIAJERO INGRESADO";
		    gotoxy(12,9); cout << "Nombre: " << viajero[a].nombre;
	        gotoxy(12,10); cout << "Nacionalidad: " << viajero[a].nacionalidad;
	    	gotoxy(12,11); cout << "Edad: " << viajero[a].edad;
		    gotoxy(12,12); cout << "Sexo: " << viajero[a].sexo;
		    gotoxy(12,13); cout << "Ingrese el lugar del que viene el viajero: ";
		    getline(cin, ingreso[a].lugar_ingreso);
		    gotoxy(12,14); cout << "Ingrese el dia de entrada: ";
		    getline(cin, fech[a].dia);
		    gotoxy(12,15); cout << "Ingrese el mes de entrada: ";
		    getline(cin, fech[a].mes);
		    gotoxy(12,16); cout << "Ingrese el anio de entrada: ";
		    getline(cin, fech[a].anio);
		    total = total + 1;
		    registro[a].salida_entrada = 'entrada';
	    }else{
		    gotoxy(12,8); cout << "No se ha encontrado el viajero, intente de nuevo";
		    getch();
		    registrar();
	}
	
	}else if(ing == '2'){
		
		gotoxy(12,7); cout << "Ingrese el id del viajero (debe de estar registrado previamente):";
		getline(cin, id_viaj);
		
		for(i = 0; i < (num_viajeros + 1); i++){
        if(id_viaj == viajero[i].id){
	        b = 1;
		    a = i;
	    	break;
	    }else{
		    b = 0;
	    }
	}
 
	    if(b == 1){
	    	gotoxy(12,8); cout << "DATOS DEL VIAJERO INGRESADO";
		    gotoxy(12,9); cout << "Nombre: " << viajero[a].nombre;
	        gotoxy(12,10); cout << "Nacionalidad: " << viajero[a].nacionalidad;
	    	gotoxy(12,11); cout << "Edad: " << viajero[a].edad;
		    gotoxy(12,12); cout << "Sexo: " << viajero[a].sexo;
		    gotoxy(12,13); cout << "Ingrese el lugar de destino del viajero: ";
		    getline(cin, salida[a].lugar_destino);
		    gotoxy(12,14); cout << "Ingrese el dia de salida: ";
		    getline(cin, fech[a].dia);
		    gotoxy(12,15); cout << "Ingrese el mes de salida: ";
		    getline(cin, fech[a].mes);
		    gotoxy(12,16); cout << "Ingrese el anio de salida: ";
		    getline(cin, fech[a].anio);
		    total = total + 1;
		    registro[a].salida_entrada = 'salida';
	    }else{
		    gotoxy(12,8); cout << "No se ha encontrado el viajero, intente de nuevo";
		    getch();
		    registrar();	
}
	}else{
		gotoxy(12,7); cout << "Debe ingresar una opcion valida, intente de nuevo: ";
		ing = '3';
	}
}while(ing == '3');
	SetConsoleTextAttribute (hConsoleHandle, 9);
	
	gotoxy(12,18); cout << "Desea regitrar un nuevo ingreso o salida? S/N";
	conti=getch();	
		
	if(conti == 's' || conti == 'S'){
		registrar();
	}else{
		Menu();
	}
}
// --------------------------------------------------------------------------- borrar

void borrar(){
	
	system("cls");
	
	SetConsoleTextAttribute (hConsoleHandle, 7);
	
	cuadro(10,5,88,16);
	cuadro(40,2,63,4);
	
	SetConsoleTextAttribute (hConsoleHandle, 9);
	gotoxy(43,3); cout << "-ELIMINAR VIAJERO-";
	
	
	SetConsoleTextAttribute (hConsoleHandle, 9);

	
	gotoxy(12,6); cout << "Id del viajero a eliminar:";
	getline(cin, id_viaj);
	
	for(i = 0; i < (num_viajeros + 1); i++){
        if(id_viaj == viajero[i].id){
	        b = 1;
		    a = i;
	    	break;
	    }else{
		    b = 0;
	}
}
	if(b == 1){
		gotoxy(12,7); cout << "Nombre: " << viajero[a].nombre;
		gotoxy(12,8); cout << "Edad: " << viajero[a].edad;
		gotoxy(12,9); cout << "Sexo: " << viajero[a].sexo;
		gotoxy(12,10); cout << "Nacionalidad: " << viajero[a].nacionalidad;
		gotoxy(12,11); cout << "Desea eliminar al viajero? S / N";
		conti=getch();	
		
    	if(conti == 's' || conti == 'S'){
	    	viajero[a].edad = 'no existe';
			viajero[a].id = 'no existe';
			viajero[a].nombre = 'no existe';
			viajero[a].sexo = 'no existe';
			viajero[a].nacionalidad = 'no existe';
			gotoxy(12,12); cout << "El viajero ha sido eliminado";
	   }else{
	   	    gotoxy(12,12); cout << "Pulse tecla para volver al inicio";
	   	    getch();
	    	borrar();
       } 
	}else{
		gotoxy(12,7); cout << "No se ha encontrado al viajero";
	}
	
	gotoxy(12,14); cout << "Desea eliminar otro viajero? S/N";
	conti=getch();	
		
	if(conti == 's' || conti == 'S'){
		borrar();
	}else{
		Menu();
	}

}
// --------------------------------------------------------------------------- consultar

void consultar(){
	
	system("cls");
	
	SetConsoleTextAttribute (hConsoleHandle, 7);
	
	cuadro(10,5,88,16);
	cuadro(40,2,63,4);
	
	SetConsoleTextAttribute (hConsoleHandle, 9);
	gotoxy(43,3); cout << "-CONSULTAR VIAJERO-";
	
	
	SetConsoleTextAttribute (hConsoleHandle, 9);

	
	gotoxy(12,6); cout << "Id del viajero a consultar:";
	getline(cin, id_viaj);
	
	for(i = 0; i < (num_viajeros + 1); i++){
        if(id_viaj == viajero[i].id){
	        b = 1;
		    a = i;
	    	break;
	    }else{
		    b = 0;
	}
}
	if(b == 1){
		gotoxy(12,7); cout << "Nombre: " << viajero[a].nombre;
		gotoxy(12,8); cout << "Edad: " << viajero[a].edad;
		gotoxy(12,9); cout << "Sexo: " << viajero[a].sexo;
		gotoxy(12,10); cout << "Nacionalidad: " << viajero[a].nacionalidad;
		
	}else{
		gotoxy(12,7); cout << "No se ha encontrado al viajero";
	}
	
	gotoxy(12,15); cout << "Desea consultar otro viajero? S/N";
	conti=getch();	
		
	if(conti == 's' || conti == 'S'){
		consultar();
	}else{
		Menu();
	}
}
// --------------------------------------------------------------------------- reporte

void reporte(){
	
	for(i = 1; i < (num_viajeros + 1); i++){
		system("cls");
		
		SetConsoleTextAttribute (hConsoleHandle, 7);
	    cuadro(10,5,88,16);
	    cuadro(40,2,67,4);
		
	    SetConsoleTextAttribute (hConsoleHandle, 9);
	    gotoxy(43,3); cout << "-REPORTE-";
	
	    gotoxy(12,6); cout << "TOTAL DE ENTRADAS Y SALIDAS: " << total;
		gotoxy(12,7); cout << "Id:" << viajero[i].id;
 	    gotoxy(12,8); cout << "Nombre: " << viajero[i].nombre;
	    gotoxy(12,9); cout << "Edad: " << viajero[i].edad;
		gotoxy(12,10); cout << "Sexo: " << viajero[i].sexo;
		gotoxy(12,11); cout << "Nacionalidad: " << viajero[i].nacionalidad;
		gotoxy(12,13); cout << "Presiones tecla para pasar al siguente viajero";
		getch();
}
	
	gotoxy(12,15); cout << "PRESIONE TECLA PARA VOLVER AL INICIO";
	getch();	
	Menu();
}
// --------------------------------------------------------------------------- MENU PRINCIPAL

void Menu(){
	
char opc;
	
	do{
		

		system("cls");
		
		SetConsoleTextAttribute (hConsoleHandle, 7);
		cuadro(10,5,88,16);
		cuadro(40,2,67,4);
		
		SetConsoleTextAttribute (hConsoleHandle, 9);
		gotoxy(43,3); cout << "-CONTROL DE MIGRACION-";
		gotoxy(12,6); cout << "(1) INGRESAR VIAJERO";
		gotoxy(12,7); cout << "(2) INGRESO AL PAIS";
		gotoxy(12,8); cout << "(3) BORRAR VIAJERO";
		gotoxy(12,9); cout << "(4) CONSULTAR VIAJERO";
		gotoxy(12,10); cout << "(5) REPORTE DE ENTRADAS Y SALIDAS";
		
		SetConsoleTextAttribute (hConsoleHandle, 4);
		gotoxy(72,15); cout << "(6) ***SALIR***";

		
		SetConsoleTextAttribute(hConsoleHandle,9);
		gotoxy(12,15); cout << "INGRESE LA OPCION:";
		opc=getch();

		switch(opc){
			
		case '1': agregar(); break; 
		case '2': registrar(); break; 
		case '3': borrar(); break;
		case '4': consultar(); break; 
		case '5': reporte(); break; // todos los viajeros
		case '6': 
				
			system("cls");
			
			SetConsoleTextAttribute (hConsoleHandle, 7);
			
			
			SetConsoleTextAttribute (hConsoleHandle, 9);
			gotoxy(11,6); cout << "Estas seguro que quieres salir del sistema";
			gotoxy(11,7); cout << "Desea salir del programa S/N";
			conti=getch();

			if (conti=='N' || conti=='n')
				Menu();
			else if (conti=='S' || conti=='s')
			    a = 1;
				break; 
			    
}
}while(a == 0);
}




int main(){
	
	Menu();
	
	return 0;
}
