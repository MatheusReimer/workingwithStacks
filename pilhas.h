#ifndef PILHAS_H
#define PILHAS_H


using namespace std;



template<typename Tipo>
struct TElementoP{
    Tipo dado;


    TElementoP<Tipo> *proximo;
};

template<typename Tipo>
struct TPilha{
    TElementoP<Tipo>*topo;
};
                                                    //INICIANDO A PILHA
template<typename Tipo>
void startP(TPilha<Tipo> & p){
    p.topo=nullptr;
}
                                                        //CHECANDO O TAMANHO DA PILHA
template<typename Tipo>
int checkPSize(TPilha<Tipo> &p){
    int contador=1;
    if(p.topo==NULL){
        return contador=0;
    }
    TElementoP<Tipo> * navegador = new TElementoP<Tipo>;
    navegador = p.topo;

    while(navegador!=NULL){
        contador++;
        navegador= navegador->proximo;
    }

    return contador;
}
                                                        //FUNCAO FACILITADORA
template<typename Tipo>
TElementoP<Tipo>* criarElementoPilha(Tipo dado){
    TElementoP<Tipo> * conteiner = new TElementoP<Tipo>;
    conteiner->dado = dado;
    conteiner->proximo = NULL;

    return conteiner;

}
                                                            //PUSH

template<typename Tipo>
void push(TPilha<Tipo> & p, Tipo dado){
    TElementoP<Tipo>*novo = criarElementoPilha(dado);
    TElementoP<Tipo>*temp = new TElementoP<Tipo>;
    temp =p.topo;
    p.topo = novo;
    novo->proximo = temp;

}
                                                                //POP
template<typename Tipo>
void pop(TPilha<Tipo>&p){
    if(p.topo==NULL){
        cout<<"Stack Underflow"<<endl;
    }
    p.topo = p.topo->proximo;
}


                                                                   //CHECANDO SE O ITEM ESTA NA PILHA
template<typename Tipo>
bool checkPItem(TPilha<Tipo>p, Tipo item){
    TElementoP<Tipo>*navegador = new TElementoP<Tipo>;
    navegador = p.topo;
    while(navegador!=NULL){

        if(navegador->dado==item){

            return true;
        }
         navegador = navegador->proximo;
    }
    cout<<"Nao tem na lista"<<endl;
    return false;
}
                                                                //PEGANDO O INDICE
template<typename Tipo>
int getIndex(TPilha<Tipo>p, Tipo item){
    if(checkPItem(p,item)==false){
        cout<<"Item inexistente"<<endl;
    }
    TElementoP<Tipo>*navegador = new TElementoP<Tipo>;
    navegador = p.topo;
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

                                                                //PRINTANDO PILHA
template<typename Tipo>
void printP(TPilha<Tipo> p){
    TElementoP<Tipo>*nav = p.topo;
    while(nav!=NULL){
        cout<<nav<<endl;
        nav=nav->proximo;

    }
}



#endif // PILHAS_H
