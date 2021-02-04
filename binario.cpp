#include<fstream>
#include<iostream>

using namespace std;

void agregar();
void mostrar();

struct info{
	char nombre[50];
	char apellido[50];
	char direccion[50];
}datos;

void Guardar (info guardar){
	try{
		fstream archivo;
		archivo.open("information.bin", ios::out | ios::app | ios::binary);
		archivo.write((char *)&guardar, sizeof(info));
		archivo.close();
	} catch (...){
		cout<<" ERROR, No se pueden agregar los datos. fn 'Guardar' "<<endl;
	}
}

void agregar(){
	
	char temp[2];
	
	cin.getline(temp,2);
	cout<<endl<<" Nombre: ";
	cin.getline(datos.nombre,50);
	cout<<" Apellido: ";
	cin.getline(datos.apellido,50);
	cout<<" Direccion: ";
	cin.getline(datos.direccion,50);
	Guardar(datos);
}

void mostrar (){
	info mostrar;
	
	fstream archivo("information.bin", ios::in | ios::binary);
	if(archivo.fail())
		cerr<<endl<<" Erro al abrir el archivo information.bin"<<endl;
	else
		while(!archivo.eof()){
			archivo.read((char *)&mostrar, sizeof (info));
			
			if (!archivo.eof()){
				cout<<endl<<"  Nombre: "<<mostrar.nombre<<endl;
				cout<<"  Apellido: "<<mostrar.apellido<<endl;
				cout<<"  Direccion: "<<mostrar.direccion<<endl;
			}
		}
		archivo.close();
}

int main() {
	
	int opcion=0;
	
	do{
		cout<<"\n\n----- Menu -----\n\n"<<endl;
		cout<<"  1. Agregar"<<endl;
		cout<<"  2. Mostrar"<<endl;
		cout<<"  3. Salir"<<endl;
		cout<<endl<<" Que opcion desea elegir: ";
		cin>>opcion;
		
		switch(opcion){
			
			case 1: 
					agregar();
					break;
			case 2:
					mostrar();
					break;
		}
	}while (opcion !=3);
	
	return 0;
}