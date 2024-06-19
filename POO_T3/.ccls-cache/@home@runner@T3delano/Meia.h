#ifndef Meia_h
#define Meia_h

#include "Jogador.h"
#include <string>
#include <iostream>
using namespace std;

class Meia : public Jogador{
  public:
    //construtor da classe Meia
    Meia(unsigned long int CPF,string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso,int drible);

    //destrutor da classe Meia
    ~Meia();

    //metodos getters e setters da classe Meia
    int getDrible()const;
    void setDrible(int drible);
    virtual int getPosicao()const;
    virtual int getOverall()const;

    //metodo responsavel por imprimir os dados do meia
    virtual void imprime()const;

  private:
    //atributo privado da classe Meia
    int drible;
};
#endif