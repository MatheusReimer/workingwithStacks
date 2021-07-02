#ifndef FILAS_H
#define FILAS_H
using namespace std;

template<typename Tipo>
struct TElementoF{
    Tipo dado;
    TElementoF<Tipo> *proximo;
};

template<typename Tipo>
struct TFila{
    TElementoF<Tipo>*ultimo;
};


template<typename Tipo>
startF(TFila<Tipo> &f){
    f.ultimo=NULL;
}


template<typename Tipo>
TElementoF<Tipo>* criarElementoFila(Tipo dado){
    TElementoF<Tipo> * conteiner = new TElementoF<Tipo>;
    conteiner->dado = dado;
    conteiner->proximo = NULL;

    return conteiner;

}

template<typename Tipo>
QueueFila(TFila<Tipo>&f, Tipo dado){
    TElementoF<Tipo>*novo = criarElementoFila(dado);
    TElementoF<Tipo>*temp = new TElementoF<Tipo>;
    temp =f.ultimo;
    f.ultimo = novo;
    novo->proximo = temp;


}

template<typename Tipo>
void DeQueue(TFila<Tipo>&f){
    if(f.ultimo==NULL){
        cout<<"Stack Underflow"<<endl;
    }

    TElementoF<Tipo>*navegador = new TElementoF<Tipo>;
    TElementoF<Tipo>*penultimo = new TElementoF<Tipo>;
    navegador=f.ultimo;
    while(navegador->proximo!=NULL){
        penultimo = navegador;
        navegador= navegador->proximo;
    }
    penultimo->proximo=NULL;
    delete navegador;

}
template<typename Tipo>
bool checkFItem(TFila<Tipo>f, Tipo item){
    TElementoF<Tipo>*navegador = new TElementoF<Tipo>;
    navegador = f.ultimo;
    while(navegador!=NULL){

        if(navegador->dado==item){

            return true;
        }
         navegador = navegador->proximo;
    }

    return false;
}


template<typename Tipo>
int getIndexF(TFila<Tipo>f, Tipo item){
    if(checkFItem(f,item)==false){
        cout<<"Item inexistente"<<endl;
    }
    TElementoF<Tipo>*navegador = new TElementoF<Tipo>;
    navegador = f.ultimo;
    int index = 0;

    while(navegador!=NULL){
        if(navegador->dado==item){
            cout<<index<<endl;
            return index;
        }
        index ++;
        navegador= navegador->proximo;

    }
}
template<typename Tipo>
int tamanhoDaFila(TFila<Tipo>f){
    TElementoF<Tipo>*navegador = new TElementoF<Tipo>;
    navegador=f.ultimo;

    int contador=0;
    while(navegador!=NULL){
        contador++;

        navegador=navegador->proximo;

    }

    return contador;
}


template<typename Tipo>
void printF(TFila<Tipo> p){
    TElementoF<Tipo>*nav = p.ultimo;
    while(nav!=NULL){
        cout<<nav<<endl;
        nav=nav->proximo;

    }
}


#endif // FILAS_H
