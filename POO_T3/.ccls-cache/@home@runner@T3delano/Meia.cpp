#include "Meia.h"
#include <iostream>
using namespace std;

//consrutor da classe Meia
Meia::Meia(unsigned long int CPF,string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso,int drible) : Jogador(CPF,nome, idade, altura, velocidade, preparo_fisico, passe, peso), drible(drible){
  
}

//destrutor da classe Meia
Meia::~Meia(){
  cout << "Destrutor Meia" << endl;
}

//metodos getters e setters
int Meia::getDrible()const{
  return drible;
}

void Meia::setDrible(int drible){
  this->drible = drible;
}

int Meia::getPosicao()const{
  return MEIA;
}

//metodo abstrato Overral
//indica a qualidade dele pela posicao dele, drible tem mais peso.
//usado para comparar jogadores

int Meia::getOverall()const{
  double peso = getPeso();
  double altura = (getAltura())/100;
  int Overall =  (getPreparo_fisico() + getPasse() + 3*drible + getVelocidade() + altura - (getIdade())/5 )/7;
  double IMC = peso/(altura*altura);
  if(IMC >  18.5 && IMC < 24.9){ //verifica se o jogador esta em forma
    Overall = Overall + peso/5; 
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
void Meia::imprime()const{
  Jogador::imprime();
  cout << "Drible: " << getDrible() << endl;
}