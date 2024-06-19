#ifndef CADASTRO_H
#define CADASTRO_H

#include "Jogador.h"
#include <vector>
using namespace std;

class Cadastro {
  public:
    //construtor da classe cadastro
    Cadastro(string fileName);

    //destrutor da classe cadastro
    virtual ~Cadastro();

    //metodo responsavel por adicionar jogador
    bool adiciona(int tipo);

    //metodos responsaveis por imprimir os dados dos jogadores
    void imprime(bool sorted = false); //imprime ordenado
    void imprime(unsigned long int CPF); //imprime jogador especifico

    //metodo responsavel por remover jogador
    bool remove(unsigned long int CPF);

    //metodo responsavel por atualizar os dados do jogador
    bool atualiza(unsigned long int CPF);

    static char opcao();

  private:
    //metodos privados da classe cadastro
    void grava();
    void recupera();
    int indice(unsigned long int CPF);

    //atributos privados da classe cadastro
    string fileName;
    vector<Jogador *> jogadores;
};

#endif /* CADASTRO_H */