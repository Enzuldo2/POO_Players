#include <iostream>
#include "Cadastro.h"
#include "Jogador.h"
#include "Atacante.h"
#include "Defesa.h"
#include "Meia.h"
using namespace std;
/*
----------------------------------------------------------------

Enzo Dezem Alves RA - 801743
Eduardo Marcondes Nunes de Matos RA - 823020

----------------------------------------------------------------
Adicicione um Atacante - Delano, CPF, Suas habilidades no futebol,
Adicione um Meia - Jander, CPF, Suas habilidades no futebol,
Adicione um Defesa - Nicolas, CPF, Suas habilidades no futebol,

Imprima as informções de cada jogador, ordenados por overral ou não, ou apenas um jogador específico atraves do CPF

Após muito treino, os jogadores melhoraram sua habilidades, então atualize as informações deles.

imprima novamente os jogadores, ordenados por overral ou não, ou apenas um jogador específico atraves do CPF

Após acabar o contrato, o jogador precisa ser removido da lista, então remova ele pelo CPF.

Imprima novamente os jogadores, ordenados por overral ou não, ou apenas um jogador específico atraves do CPF
----------------------------------------------------------------
*/

int main() {
  char op;
  unsigned long int CPF;

  //arquivo onde serão escritos os dados
  Cadastro cadastro("info.dat");

  //menu de opções
  do{
    op = Cadastro::opcao();
    switch (op) {
      //imprime todos jogadores sem ordenar
      case 'I': { 
        cadastro.imprime();
        break;
      }
      
      //imprime jogador especifico atraves do CPF
      case 'C': {
        cout << "CPF: ";
        cin >> CPF;
        cadastro.imprime(CPF);
        break;
      }

      //imprime todos jogadores ordenados pelo Overall
      case 'O': {
        cadastro.imprime(true);
        break;
      }

      //adiciona jogador de Defesa na lista
      case 'D': {
        cadastro.adiciona(DEFESA);
        break;
      }

      //adiciona jogador de Atacante na lista
      case 'A':{
        cadastro.adiciona(ATACANTE);
        break;
      }

      //adiciona jogador de Meia na lista
      case 'M': {
        cadastro.adiciona(MEIA);
        break;
      }

      //atualiza qualidades de um jogador atraves do CPF
      case 'S': {
        cout << "CPF: ";
        cin >> CPF;
        bool ok = cadastro.atualiza(CPF);
        cout << "Atualização " << (ok ? "ok" : "não ok") << endl;
        break;
      }

      //remove jogador da lista atraves do CPF
      case 'R': {
        cout << "CPF: ";
        cin >> CPF;
        bool ok = cadastro.remove(CPF);
        cout << "Remoção " << (ok ? "ok" : "não ok") << endl;
        break;
      }
    }
    cout << endl;
  } while (op != 'F'); //fim do programa ao selecionar a opção F

  return 0;
}