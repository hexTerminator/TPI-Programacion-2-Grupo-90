#include <iostream>
#include <cstring>
#include "roles.h"
#include "arcRol.h"
using namespace std;

void Roles::setIdRol(int idRol){
    _idRol=idRol;
}

void Roles::setNombreRol (string nombreRol){
    strcpy(_nombreRol,nombreRol.c_str());
}

void Roles::setActivo(bool activo){
    _activo=activo;
}

int Roles::getIdRol(){
    return _idRol;
}

string Roles::getNombreRol(){
    return _nombreRol;
}

bool Roles::getActivo(){
    return _activo;
}

void Roles::Cargar(){
    arcRoles arRol;
    int aux;
    char auxN[30];
    bool auxA;

    cout<<"ID DEL ROL"<<endl;
    cin>>aux;
    setIdRol(aux);

    cout<<"NOMBRE DEL ROL"<<endl;
    cin>>auxN;
    setNombreRol(auxN);

    cout<<"ESTADO DEL ROL"<<endl;
    cin>>auxA;
    setActivo(auxA);
}

void Roles::Mostrar(){
    cout<<"Id. Rol: "<<_idRol<<endl;
    cout<<"Nombre del Rol: "<<_nombreRol<<endl;
    cout<<"Estado: "<<endl;
    if (_activo){
        cout<<"Activo"<<endl;
    } else {
        cout<<"Inactivo"<<endl;
    }
}
