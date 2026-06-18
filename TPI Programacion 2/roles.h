#pragma once
#include <string>

class Roles{
private:
    int _idRol;
    char _nombreRol[30];
    bool _activo;

public:
    void setIdRol(int idRol);
    void setNombreRol (std::string nombreRol);
    void setActivo(bool activo);
    int getIdRol();
    std::string getNombreRol();
    bool getActivo();
    void Cargar();
    void Mostrar();
};
