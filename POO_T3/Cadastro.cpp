#include "Cadastro.h"
#include "Atacante.h"
#include "Meia.h"
#include "Defesa.h"
#include <algorithm>
#include <fstream>
using namespace std;

//construtor da classe Cadastro
Cadastro::Cadastro(string fileName) : fileName(fileName){
  recupera(); //coloca o que ja esta no arquivo no vetor
}

//destrutor da classe Cadastro
Cadastro::~Cadastro() {
  cout << "Destrutor de Cadastro" << endl;
}

//metodo responsavel por gravar as informacoes do cadastro no arquivo
//toda vez que chamado vai rescrever o vetor de jogadores no arquivo info.dat por motivos de organizacao.
void Cadastro::grava() {
  unsigned long int CPF;
  int tam, tipo, idade, passe, altura, velocidade, preparo_fisico, chute, defesa, drible;
  string nome;
  double peso;
  Atacante *a1;
  Defesa *d1;
  Meia *m1;

  ofstream saida(fileName, ios::binary); //descreve os dados do arquivo como binario
  for (long unsigned int i = 0; i < jogadores.size(); i++) {
    // Escrevendo o tipo de jogador (Atacante, Meia ou Defesa)
    tipo = jogadores[i]->getPosicao();
    saida.write(reinterpret_cast<char *>(&tipo), sizeof(tipo));

    // Escrevendo o CPF
    CPF = jogadores[i]->getCPF();
    saida.write(reinterpret_cast<char *>(&CPF), sizeof(CPF));

    // Escrevendo o nome
    nome = jogadores[i]->getNome();
    tam = nome.size();

    // Escrevendo o tamanho da string (nome)
    saida.write(reinterpret_cast<char *>(&tam), sizeof(tam));

    // Escrevendo os caracteres da string (nome)
    saida.write(reinterpret_cast<char *>(&nome[0]), tam);

    // Escrevendo a idade
    idade = jogadores[i]->getIdade();
    saida.write(reinterpret_cast<char *>(&idade), sizeof(idade));

    //escrevendo a altura
    altura = jogadores[i]->getAltura();
    saida.write(reinterpret_cast<char *>(&altura), sizeof(altura));

    //escrevendo a velocidade
    velocidade = jogadores[i]->getVelocidade();
    saida.write(reinterpret_cast<char *>(&velocidade), sizeof(velocidade));

    //escrevendo o preparo fisico
    preparo_fisico = jogadores[i]->getPreparo_fisico();
    saida.write(reinterpret_cast<char *>(&preparo_fisico), sizeof(preparo_fisico));

    //escrevendo o passe
    passe = jogadores[i]->getPasse();
    saida.write(reinterpret_cast<char *>(&passe), sizeof(passe));

    //escrevendo o peso
    peso = jogadores[i]->getPeso();
    saida.write(reinterpret_cast<char *>(&peso), sizeof(peso));


    //escreve as caracteristicas especificas dos jogadores de cada posição
    //(atributos da classe Atacante, Meia, Defesa)
    switch (tipo) {

      //escreve o chute
      case ATACANTE: {
        a1 = dynamic_cast<Atacante *>(jogadores[i]);
        chute = a1->getChute();
        saida.write(reinterpret_cast<char *>(&chute), sizeof(chute));

        break;
      }

      //escreve a defesa
      case DEFESA: {
        d1 = dynamic_cast<Defesa *>(jogadores[i]);
        defesa = d1->getDefesa();

        saida.write(reinterpret_cast<char *>(&defesa), sizeof(defesa));
        break;
      }
      
      //escreve o drible
      case MEIA:{
        m1 = dynamic_cast<Meia *>(jogadores[i]);
        drible = m1->getDrible();
        saida.write(reinterpret_cast<char *>(&drible), sizeof(drible));
      } 
    }
  }
  saida.close();
}

//metodo resposavel por recuperar as informacoes do arquivo
void Cadastro::recupera() {
  unsigned long int CPF;
  int tam, tipo, idade, passe, altura, velocidade, preparo_fisico, chute, defesa, drible;
  string nome;
  double peso;

  //abriu como leitura
  ifstream entrada(fileName, ios::binary);

  if (entrada.is_open()) {
    jogadores.clear();

    // Lendo o tipo
    entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));

    while (entrada.good()) {
      // Lendo o CPF
      entrada.read(reinterpret_cast<char *>(&CPF), sizeof(CPF));

      // Lendo o tamanho da string (nome)
      entrada.read(reinterpret_cast<char *>(&tam), sizeof(tam));
      nome.resize(tam);

      // Lendo os caracteres da string (nome)
      entrada.read(reinterpret_cast<char *>(&nome[0]), tam);

      // Lendo a idade
      entrada.read(reinterpret_cast<char *>(&idade), sizeof(idade));

      //lendo a altura
      entrada.read(reinterpret_cast<char *>(&altura), sizeof(altura));

      //lendo a velocidade
      entrada.read(reinterpret_cast<char *>(&velocidade), sizeof(velocidade));

      //lendo o preparo fisico
      entrada.read(reinterpret_cast<char *>(&preparo_fisico), sizeof(preparo_fisico));

      //lendo o passe
      entrada.read(reinterpret_cast<char *>(&passe), sizeof(passe));

      //lendo o peso
      entrada.read(reinterpret_cast<char *>(&peso), sizeof(peso));
    

      //lendo as caracteristicas especificas dos jogadores de cada posição
      //(atributos da classe Atacante, Meia, Defesa)
      switch (tipo) {
        case ATACANTE: {
          // Lendo o tamanho da string (especialidade)
          entrada.read(reinterpret_cast<char *>(&chute), sizeof(chute));
          jogadores.push_back(new Atacante(CPF,nome,idade,altura,velocidade,preparo_fisico,passe,peso,chute));

          break;
        }
        case DEFESA: {
          // Lendo o tamanho da string (especialidade)
          entrada.read(reinterpret_cast<char *>(&defesa), sizeof(defesa));

          // Lendo os caracteres da string (especialidade)
          jogadores.push_back(new Defesa(CPF,nome,idade,altura,velocidade,preparo_fisico,passe,peso,defesa));
        
          break;
        }
        case MEIA: {
          // Lendo o tamanho da string (especialidade)
          entrada.read(reinterpret_cast<char *>(&drible), sizeof(drible));
          jogadores.push_back(new Meia(CPF,nome,idade,altura,velocidade,preparo_fisico,passe,peso,drible));

          break;
        }
      }
      // Lendo o tipo
      entrada.read(reinterpret_cast<char *>(&tipo), sizeof(tipo));
    }
  }
  entrada.close();
}

//metodo responsavel por adicionar um jogador na lista
bool Cadastro::adiciona(int tipo) {
  unsigned long int CPF;
  int idade,passe,altura,velocidade,preparo_fisico,chute,defesa,drible;
  string nome;
  double peso;
  Jogador* j1;

  cin.ignore();
  cout << "Nome: ";
  getline(cin, nome);
  cout << "CPF: ";
  cin >> CPF;
  cout << "Idade: ";
  cin >> idade;
  cout << "Altura(em centimetros ,sem virgula): ";
  cin >> altura;
  cout<<endl;
  cout << "------qualidades do atleta numa escala de 1 a 100------------" << endl;
  cout<<endl;
  cout << "Velocidade: ";
  cin >> velocidade;
  cout << "Preparo Físico: ";
  cin >> preparo_fisico;
  cout << "Passe: ";
  cin >> passe;
  cout << "Peso: ";
  cin >> peso;

  switch(tipo) {
    //adiciona um jogador de Ataque
    case ATACANTE: {
      cout << "Chute: ";
      cin >> chute;
      j1 = new Atacante(CPF,nome,idade,altura,velocidade,preparo_fisico,passe,peso,chute);
      break;
    }

    //adiciona jogador de Defesa
    case DEFESA: {
      cout << "Defesa: ";
      cin >> defesa;
      j1 = new Defesa(CPF,nome,idade,altura,velocidade,preparo_fisico,passe,peso,defesa);
      break;
    }

    //adiciona um jogador de Meia
    case MEIA:{
      cout << "Drible: ";
      cin >> drible;
      j1 = new Meia(CPF,nome,idade,altura,velocidade,preparo_fisico,passe,peso,drible);
    }
  }
  
  //grava os dados do jogador no arquivo
  jogadores.push_back(j1);
  grava(); 
  return true;
}

//metodo responsavel por atualizar as caracteristicas de um jogador da lista usando o CPF
bool Cadastro::atualiza(unsigned long int CPF) {
  double peso;
  int tipo,passe,velocidade,preparo_fisico,chute,defesa,drible;
  
  //outros atributos nao sao mutaveis com treinamento.
  bool ok = false;
  int pos = indice(CPF);
  Atacante* a1;
  Defesa* d1;
  Meia* m1;

  if (pos != -1) {
    //identifica a posicao do jogador
    tipo = jogadores[pos]->getPosicao();

    //atualiza o peso
    cout << "Peso: ";
    cin >> peso;
    jogadores[pos]->setPeso(peso);

    //atualiza o passe
    cout << "Passe: ";
    cin >> passe;
    jogadores[pos]->setPasse(passe);

    //atualiza a velocidade
    cout << "Velocidade: ";
    cin >> velocidade;
    jogadores[pos]->setVelocidade(velocidade);

    //atualiza o preparo fisico
    cout << "Preparo Físico: ";
    cin >> preparo_fisico;
    jogadores[pos]->setPreparo_fisico(preparo_fisico);

    //atualiza a caracteristica especial baseada no tipo do jogador
    switch(tipo){
      //atualiza o chute se for Atacante
      case ATACANTE:{
        a1 = dynamic_cast<Atacante *>(jogadores[pos]);
        cout << "Chute: ";
        cin >> chute;
        a1->setChute(chute);
        break;
      }

      //atualiza a defesa se for Defesa
      case DEFESA:{
        d1 = dynamic_cast<Defesa *>(jogadores[pos]);
        cout << "Defesa: ";
        cin >> defesa;
        d1->setDefesa(defesa);
        break;
      }

      //atualiza o drible se for Meia
      case MEIA: {
        m1 = dynamic_cast<Meia *>(jogadores[pos]);
        cout << "Drible: ";
        cin >> drible;
        m1->setDrible(drible);
        break;
      }
    }
    grava();
    ok = true;
  }
  return ok;
}

//metodo resposavel por remover um jogador da lista usando o CPF
bool Cadastro::remove(unsigned long int CPF) {
  bool ok = false;
  int pos = indice(CPF);

  if (pos != -1) {
    jogadores.erase(jogadores.begin() + pos);
    grava();
    ok = true;
  }
  return ok;
}

//imprime um jogador da lista em especifico usando o CPF
int Cadastro::indice(unsigned long int CPF) {
  long unsigned int tam = jogadores.size();
  long unsigned int pos = 0;

  while (pos < tam && jogadores[pos]->getCPF() != CPF) {
    pos++;
  }

  if (pos < tam) {
    return pos;
  } else {
    return -1;
  }
}

//imprime os dados de um jogador especifico atraves do CPF
void Cadastro::imprime(unsigned long int CPF) {
  int pos = indice(CPF);

  if (pos != -1) {
    jogadores[pos]->imprime();
  } else {
    cout << "CPF não encontrado";
  }
}

//imprime a lista dos jogadores ordenados pelo overral ou na ordem de insercao
void Cadastro::imprime(bool sorted) {
  vector<Jogador*> copia = jogadores;
  if (sorted) {
    sort(copia.begin(), copia.end(), Jogador::ComparaOverall);
  }
  for (long unsigned int i = 0; i < copia.size(); i++) {
    copia[i]->imprime();
    cout << endl;
  }
}

//metodo responsavel por imprimir o menu de opções
char Cadastro::opcao() {
  char c;
  cout << "[I] Imprime todos" << endl;
  cout << "[C] Imprime jogador especifico (CPF)" << endl;
  cout << "[O] Imprime ordenado (Overall)" << endl;
  cout << "[D] Adiciona jogador de Defesa" << endl;
  cout << "[A] Adiciona Atacante" << endl;
  cout << "[M] Adiciona Meia" << endl;
  cout << "[S] Atualizar Qualidades do Jogador (por CPF)" << endl;
  cout << "[R] Remove (por CPF)" << endl;
  cout << "[F] Fim" << endl;
  cout << "> ";
  cin >> c;
  return (toupper(c));
}