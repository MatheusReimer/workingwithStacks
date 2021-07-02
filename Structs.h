#ifndef STRUCTS_H
#define STRUCTS_H

#include "pilhas.h"
#include "funcoes.h"
struct Produto{
    int codigo=0;
    int pilha=0;
    int modulos;


};

struct Cliente{

    int codigoProduto1=0;
    int codigoProduto2=0;
    int codigoProduto3=0;
};


#include <iostream>
using namespace std;

ostream& operator<< (ostream& os, TPilha<Produto> produto){
    while(produto.topo!=NULL){
    os << "Codigo "<< produto.topo->dado.codigo <<endl;
    produto.topo = produto.topo->proximo;

    }
    return os;

}


#endif // STRUCTS_H
