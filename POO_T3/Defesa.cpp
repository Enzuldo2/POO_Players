#include "Defesa.h"
#include <iostream>
using namespace std;

//construtor da classe Defesa
Defesa::Defesa(unsigned long int CPF, string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso, int defesa) : Jogador(CPF, nome, idade, altura, velocidade, preparo_fisico, passe, peso), defesa(defesa){
  
}

//destrutor da classe Defesa
Defesa::~Defesa(){
  cout << "Destrutor Defesa" << endl;
}

//metodos getters e setters
int Defesa::getDefesa()const{
  return defesa;
}

void Defesa::setDefesa(int defesa){
  this->defesa = defesa;
}

int Defesa::getPosicao()const{
  return DEFESA;
}

//metodo abstrato Overral
//indica a qualidade dele pela posicao dele, defesa tem mais peso.
//usado para comparar jogadores

int Defesa::getOverall()const{
  double peso = getPeso();
  double altura = (getAltura())/100;
  int Overall =  (getPreparo_fisico() + getPasse() + 3*defesa + getVelocidade() + altura - (getIdade())/2 )/7;
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
void Defesa::imprime()const{
  Jogador::imprime();
  cout << "Defesa: " << defesa << endl;
}