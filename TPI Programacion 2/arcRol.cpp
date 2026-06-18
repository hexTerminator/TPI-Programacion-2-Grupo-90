#include <iostream>
#include <cstring>
#include "arcRol.h"
#include "roles.h"
using namespace std;

arcRoles::arcRoles (bool vacio, const char* nombre){
    strcpy(_nombre,nombre);
    if(vacio){
      FILE *p=fopen(nombre,"wb");
      if (p==NULL){
        cout<<"ERROR DE ARCHIVO";
        exit (1);
      }
        fclose(p);
    }
}

Roles arcRoles::leerRegistro(int pos){
    Roles reg;
    FILE *pRol=fopen(_nombre,"rb");

    if (pRol==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return reg;
    }
    fseek (pRol, pos*sizeof reg, 0);
    fread (&reg, sizeof reg, 1, pRol);
    fclose (pRol);
    return reg;
}
int arcRoles::contarRegistro(){
    FILE *p;
    p=fopen(_nombre, "rb");
    if (p==nullptr){return 0;}
    fseek(p,0,2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof(Roles);
}

bool arcRoles::grabarRegistro(Roles obj){
    FILE *pRol;

    pRol=fopen(_nombre, "ab");
    if (pRol==nullptr){
        return false;
    }
    bool escrito=fwrite(&obj, sizeof obj, 1, pRol);

    fclose (pRol);
    return escrito;
}

int arcRoles::buscarRegistro(int idRoles){
    Roles reg;
    int pos=0;
    FILE *pRol=fopen(_nombre, "rb");

    if (pRol==nullptr){
        return -1;
    }
    while (fread(&reg, sizeof reg, 1, pRol)==1){
        if (idRoles==reg.getIdRol()){
            fclose (pRol);
            return pos;
        }
        pos++;
    }
    fclose(pRol);

    return -1;
}

bool arcRoles::modificarRegistro(Roles obj, int pos){
    FILE *pRol=fopen(_nombre, "rb+");
    if (pRol==nullptr){
        return false;
    }
    fseek(pRol, pos*sizeof obj, 0);
    bool escrito=fwrite(&obj, sizeof obj, 1, pRol);
    fclose (pRol);
    return escrito;
}

void arcRoles::listarArchivo(){
    Roles obj;
    FILE *pRol=fopen(_nombre, "rb");
    if (pRol==nullptr){
        return;
    }
    while (fread(&obj, sizeof obj, 1, pRol)!=0){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pRol);

}
/*
bool arcRoles::limpiarArchivo();
void arcRoles::altaRegistro();
void arcRoles::bajaRegistro();
bool arcRoles::bajaFisica(int pos);
*/
