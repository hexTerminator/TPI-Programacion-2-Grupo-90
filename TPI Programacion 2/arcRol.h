#pragma once
#include "roles.h"

class arcRoles{
private:
    char _nombre[30];
public:

    arcRoles (bool vacio=false, const char* nombre="arcRoles.dat");
    
    Roles leerRegistro(int pos);
    int contarRegistro();
    bool grabarRegistro(Roles obj);
    int buscarRegistro(int idRoles);
    bool modificarRegistro(Roles obj, int pos);
    void listarArchivo();
    bool limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
    bool bajaFisica(int pos);
};
