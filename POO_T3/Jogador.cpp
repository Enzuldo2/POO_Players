#include "Jogador.h"

//construtor da classe Jogador
Jogador::Jogador(unsigned long int CPF,string nome, int idade, double altura, int velocidade, int preparo_fisico, int passe, double peso) : CPF(CPF), nome(nome) , idade(idade), altura(altura), velocidade(velocidade), preparo_fisico(preparo_fisico), passe(passe), peso(peso) {
  
}

//destrutor da classe Jogador
Jogador::~Jogador(){
  cout << "Destrutor de Jogador" << endl;
}

//metodos getters e setters
unsigned long int Jogador::getCPF() const{
  return CPF;
}

string Jogador::getNome()const{
  return nome;
}

int Jogador::getIdade()const{
  return idade;
}

double Jogador::getAltura()const{
  return altura;
}

int Jogador::getVelocidade()const{
  return velocidade;
}

int Jogador::getPreparo_fisico()const{
  return preparo_fisico;
}

int Jogador::getPasse()const{
  return passe;
}

double Jogador::getPeso()const{
  return peso;
}

void Jogador::setPeso(double peso){
  this->peso = peso;
}

void Jogador::setPasse(int passe){
  this->passe = passe;
}

void Jogador::setPreparo_fisico(int preparo_fisico){
  this->preparo_fisico = preparo_fisico;
}

void Jogador::setVelocidade(int velocidade){
  this->velocidade = velocidade;
}

//metodo compara
bool Jogador::ComparaOverall(const Jogador *j1, const Jogador *j2){
  return j1->getOverall() > j2->getOverall();
}

//metodo imprime
void Jogador::imprime()const{
  cout << "Nome: " << nome << endl;
  cout << "CPF: " << CPF << endl;
  cout << "Idade: " << idade << endl;
  cout << "Altura: " << altura << endl;
  cout << "Velocidade: " << velocidade << endl;
  cout << "Preparo Físico: " << preparo_fisico << endl;
  cout << "Passe: " << passe << endl;
  cout << "Peso: " << peso << endl;
  switch(getPosicao()){
    case ATACANTE:
      cout << "Posição: Atacante" << endl;
      break;
    case DEFESA:{
      cout << "Posição: Defesa" << endl;
      break;
    }
    case MEIA:{
      cout << "Posição: Meia" << endl;
      break;
    }
  }
  cout << "------Overall: " << getOverall()<<"------" << endl;
}