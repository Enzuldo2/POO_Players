#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <iostream>
using namespace std;

enum TIPO { ATACANTE, DEFESA, MEIA };

class Jogador{
  private:
    //atributos privados da classe Jogador
    unsigned long int CPF;
    string nome;
    int idade;
    int altura;
    int velocidade;
    int preparo_fisico;
    int passe;
    double peso;

  public:
    //construtor da classe Jogador
    Jogador(unsigned long int CPF ,string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso);

    //destrutor da classe Jogador
    virtual ~Jogador();

    //metodos getters e setters da classe Jogador
    unsigned long int getCPF()const;
    string getNome()const;
    int getIdade()const;
    double getAltura()const;
    int getVelocidade()const;
    int getPreparo_fisico()const;
    int getPasse()const;
    double getPeso()const;
    virtual int getOverall()const=0;
    void setPeso(double peso);
    void setVelocidade(int velocidade);
    void setPreparo_fisico(int preparo_fisico);
    void setPasse(int passe);
    virtual int getPosicao()const = 0; //metodo abstrato

    //metodo responsavel por comparar os jogadores baseado em seu overral
    static bool ComparaOverall(const Jogador *j1, const Jogador *j2);

    //metodo responsavel por imprimir os dados do jogador
    virtual void imprime()const;
};
#endif    
