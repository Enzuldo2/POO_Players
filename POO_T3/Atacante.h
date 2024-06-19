#ifndef ATACANTE_H
#define ATACANTE_H

#include "Jogador.h"
#include <string>
#include <iostream>
using namespace std;

class Atacante : public Jogador {
  public:
    //construtor da classe Atacante
    Atacante(unsigned long int CPF, string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso, int chute);

    //destrutor da classe Atacante
    virtual ~Atacante();

    //metodos getters e setters da classe atacante
    virtual int getPosicao()const;
    virtual int getOverall()const;
    int getChute()const;
    void setChute(int chute);

    //metodo responsavel por imprimir os dados do atacante
    void imprime()const;

  private:
    //atributo privado da classe atacante
    int chute;
};
#endif