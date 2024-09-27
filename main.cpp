#include <algorithm>
#include <iostream>
#include "Pilha.h"
#include "Fila.h"
using namespace std;

void verificarNota(Aluno & aluno) {

    TipoDadoPilha topo;
    TipoCelula frente;

    if (Pilha_Vazia()) {
        if (Fila_Frente(frente)) Pilha_Empilhar(aluno);
    }
    else if (!Pilha_Vazia()) {
        if (Pilha_Topo(topo)){
            if (aluno.nota > topo.nota) {
                Pilha_Empilhar(aluno);
            }else {
                TipoDadoPilha temp = topo;
                Pilha_Desempilhar(topo);
                Pilha_Empilhar(aluno);
                Pilha_Empilhar(temp);
            }
        }
    }
}

void printPilha() {
    Aluno topo;
    while (!Pilha_Vazia()) {
        if (Pilha_Topo(topo)) {
            printf("Aluno %d - Nota: %.2f\n", topo.matricula, topo.nota);
            Pilha_Desempilhar(topo);
        }
    }
}

void menu(Aluno aluno) {
    int opcao;
    bool condicao = true;
    while (condicao) {
        cout << "1. Adicionar aluno" << endl << "2. Imprimir notas" << endl << "3. Sair" << endl << "Digite uma opcao:" << endl ;
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Digite a matricula do aluno:" << endl;
            cin >> aluno.matricula;
            cout << "Digite a nota do aluno:" << endl;
            cin >> aluno.nota;
            Fila_Enfileirar(aluno);
            verificarNota(aluno);
            break;
            case 2:
                cout << "Imprimindo Pilha..." << endl;
                printPilha();
                condicao = false;
                break;
            case 3:
                cout << "Saindo..." << endl;
                condicao = false;
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }
    }
}



int main() {
    Aluno aluno;
    Fila_Construtor();
    Pilha_Construtor();
    menu(aluno);



    Pilha_Destrutor();
    Fila_Destrutor();
    system("pause");
    return 0;
}
