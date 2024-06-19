#ifndef DEFESA_H
#define DEFESA_H

#include "Jogador.h"
#include <string>
#include <iostream>
using namespace std;

class Defesa : public Jogador{
  public:
    //construtor da classe Defesa
    Defesa(unsigned long int CPF,string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso, int defesa);

    //destrutor da classe Defesa
    virtual ~Defesa();

    //metodos getters e setters da classe defesa
    virtual int getPosicao() const;
    virtual int getOverall() const;
    int getDefesa() const;
    void setDefesa(int defesa);

    //metodo responsavel por imprimir os dados do defesa
    virtual void imprime() const;

  private:
    //atributo privado da classe Defesa
    int defesa;
};
#endif