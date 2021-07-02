#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H
#include <iostream>
using namespace std;
#include "Structs.h"

template<typename T>
struct TElemento{
    T dado;
    string nome;
    bool lido = false;

};


template <typename T,int N>
struct TlistaGenerica
{

    TElemento<T> elementos[N];
    int quantidade;
};

template <typename T, int N>
void inicializa_lista_generica(TlistaGenerica< T, N> &l){
    l.quantidade=0;
}

template <typename T, int N>
void imprimir_lista_generica(TlistaGenerica<T, N>&l){
    cout<<"Imprimindo Lista Generica de capacidade "<< N<< endl;
    for (int i = 0; i< l.quantidade;i++){
        cout<<" Dado [" << i << "]  " << l.elementos[i].dado<<endl;
    }
}

template<typename T, int N>
void inserir_fim_lista_generica(TlistaGenerica<T,N> &l,T dado ){
    if(l.quantidade>=N){
        throw "OverFlow";
    }
    TElemento<T> el;
    el.dado = dado;
    l.elementos[l.quantidade] =el;
    l.quantidade++;

}
template<typename T, int N>
void inserir_inicio_lista_generica(TlistaGenerica<T,N> &l,T dado , string nome){
    if(l.quantidade>=N){
        throw "OverFlow";
    }
    for(int i=l.quantidade;i>0;i--){
        l.elementos[i] = l.elementos[i-1];
    }
    TElemento<T> el;
    el.dado = dado;
    el.nome = nome;
    l.elementos[0] =el;

    l.quantidade++;

}
template<typename T, int N>
void inserir_pos_lista_generica(TlistaGenerica<T,N> &l,T dado ,int pos){
    if(l.quantidade>=N){
        throw "OverFlow";
    }
    for(int i=l.quantidade;i>pos;i--){
        l.elementos[i] = l.elementos[i-1];
    }
    TElemento<T> el;
    el.dado = dado;
    l.elementos[pos] =el;
    l.quantidade++;

}
template<typename T, int N>
void busca_item_lista_generica(TlistaGenerica<T,N> &l,T dado){


}
template<typename T, int N>
void remover_da_lista_generica_ultimo(TlistaGenerica<T,N> &l){
    if(l.quantidade==0){
        cout<<"A lista já está vazia--------UNDERFLOW"<<endl;
        return;
    }
        l.quantidade--;
}
template<typename T, int N>
void remover_da_lista_generica_primeiro(TlistaGenerica<T,N> &l){
    if(l.quantidade==0){
        cout<<"A lista já está vazia"<<endl;
        return;
    }
    for(int i = 1; i<l.quantidade; i++){

        l.elementos[i-1] = l.elementos[i];
    }
    l.quantidade--;
}
template<typename T, int N>
void remover_da_lista_generica_pos(TlistaGenerica<T,N> &l ,int pos){
    if(l.quantidade==0){
        cout<<"A lista já está vazia"<<endl;
        return;
    }
    for(int i = pos; i<l.quantidade-pos; i++){

        l.elementos[i] = l.elementos[i+1];
    }
    l.quantidade--;
}

template<typename T, int N>
void obterItemDaListaGenerica(TlistaGenerica<T,N> &l ,int pos){
    if(pos>l.quantidade){
        cout<<"Elemento nao encontrado, posicao maior que a lista"<<endl;
    }else{
        for(int i=0;i<=pos;i++){
            cout<<l.elementos[i];
        }
    }

}
template<typename T ,int N>
bool buscarItemListaGenerica(TlistaGenerica<T,N> &l,Produto item ){
    for (int i = 0; i< l.quantidade;i++){
        if(item == l.elementos[i].dado){
            return true;
        }
        else{
            return false;
        }
    }
}

template<typename T, int N>
void descobrirIndiceListaGenerica(TlistaGenerica<T,N>&l, Produto item){
    for (int i = 0; i< l.quantidade;i++){
        if(item==l.elementos[i].dado){
            cout<<l.elementos[i];
        }
    }
}


#endif // LISTAGENERICA_H
