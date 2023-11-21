#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;
};

void preOrdem(NoArvore *raiz) {
    if (raiz != NULL) {
        cout << raiz->data << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

int profundidade(NoArvore *raiz) {
    int prof = 0;
    while (raiz != NULL) {
        prof += 1;
        raiz = raiz->esquerda;
    }
    return prof;
}

bool arvorePerfeita(NoArvore *raiz, int prof, int nivel) {
    if (raiz == NULL) {
        return true;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return (prof == nivel + 1);
    }

    if (raiz->esquerda == NULL || raiz->direita == NULL) {
        return false;
    }

    return arvorePerfeita(raiz->esquerda, prof, nivel + 1) && arvorePerfeita(raiz->direita, prof, nivel + 1);
}

int main(int argc, char** argv) {
	int nivel = 0;
	
    NoArvore *raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore *elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 2;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;
    raiz->esquerda = elementoEsquerda;

    NoArvore *elementoDireita = new NoArvore;
    elementoDireita->data = 3;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;
    raiz->direita = elementoDireita;

    elementoEsquerda->esquerda = new NoArvore;
    elementoEsquerda->esquerda->data = 4;
    elementoEsquerda->esquerda->esquerda = NULL;
    elementoEsquerda->esquerda->direita = NULL;

    elementoEsquerda->direita = new NoArvore;
    elementoEsquerda->direita->data = 5;
    elementoEsquerda->direita->esquerda = NULL;
    elementoEsquerda->direita->direita = NULL;

    elementoDireita->esquerda = new NoArvore;
    elementoDireita->esquerda->data = 6;
    elementoDireita->esquerda->esquerda = NULL;
    elementoDireita->esquerda->direita = NULL;

    elementoDireita->direita = new NoArvore;
    elementoDireita->direita->data = 7;
    elementoDireita->direita->esquerda = NULL;
    elementoDireita->direita->direita = NULL;
    
    /*elementoEsquerda->esquerda->esquerda = new NoArvore;
    elementoEsquerda->esquerda->esquerda->data = 8;
    elementoEsquerda->esquerda->esquerda->esquerda = NULL;
    elementoEsquerda->esquerda->esquerda->direita = NULL; */

    preOrdem(raiz);

    int prof = profundidade(raiz);

	/*PARA DEIXAR IMPERFEITA SÓ TIRAR O COMENTARIO DO ELEMENTO 8 */
	
    cout << "\nA arvore e perfeita? 1-Sim 0-Nao: " << arvorePerfeita(raiz, prof, nivel)<< endl;
	
    return 0;
}

