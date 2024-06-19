#include "Atacante.h"
#include <iostream>
using namespace std;

//construtor da classe Atacante
Atacante::Atacante(unsigned long int CPF, string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso, int chute) : Jogador(CPF, nome, idade, altura, velocidade, preparo_fisico, passe , peso), chute(chute){}

Atacante::~Atacante(){
  cout << "Destrutor Atacante" << endl;
}

//metodos getters e setters
int Atacante::getChute()const{
  return chute;
}

void Atacante::setChute(int chute){
  this->chute = chute;
}

//metodo abstrato
int Atacante::getPosicao()const{ 
  return ATACANTE;
}

//metodo abstrato Overral
//indica a qualidade dele pela posicao dele, chute tem mais peso.
//usado para comparar jogadores
int Atacante::getOverall()const{ 
  double peso = getPeso();
  double altura = (getAltura())/100;
  int Overall =  (getPreparo_fisico() + getPasse() + 3*chute + getVelocidade() + altura -  (getIdade())/2 )/7;
  double IMC = peso/(altura*altura);
  if(IMC >  18.5 && IMC < 24.9){ //verifica se o jogador esta em forma
    Overall = Overall + peso/8;
  }
  else if(IMC > 24.9 && IMC < 29.9){ 
    Overall = Overall - (peso*0.5)/8;
  }
  else{
    Overall = Overall - peso/8;
  }
  return Overall;    
}

//metodo imprime
void Atacante::imprime()const{
  Jogador::imprime();
  cout << "Chute: " << getChute() << endl;
}