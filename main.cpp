#include <algorithm>
#include <iostream>
#include "Pilha.h"
#include "Fila.h"
using namespace std;

void verificarNota() {
    TipoDadoPilha topo;
    TipoCelula frente;


    //verificar com o topo enquanto o valor da fila for menor que o valor da pilha
    while (!Fila_Vazia()) {
        if (Fila_Frente(frente.Item)){
            if (Pilha_Vazia()) {
                Pilha_Empilhar(frente.Item);
                topo = frente.Item;
                Fila_Desenfileirar(frente.Item);
            }else {
                if (frente.Item.nota < topo.nota) {
                    Fila_Enfileirar(topo);
                    Pilha_Desempilhar(topo);
                }
                else {
                    Pilha_Empilhar(frente.Item);
                    Fila_Desenfileirar(frente.Item);
                }
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

/*
void printFila() {
    TipoCelula frente;
    while (!Fila_Vazia()) {
        if (Fila_Frente(frente.Item)) {
            printf("Aluno %d - Nota: %.2f\n", frente.Item.matricula, frente.Item.nota);
            Fila_Desenfileirar(frente.Item);
        }
    }
}*/


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
                break;
            case 2:
                cout << "Imprimindo Pilha..." << endl;
                verificarNota();
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
