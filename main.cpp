#include <iostream>
#include "pilhas.h"
#include "filas.h"
#include "funcoes.h"
#include "Structs.h"

using namespace std;

int main()
{
    /*
    TPilha <int> pilha1;
    startP(pilha1);
    push(pilha1,10);
    push(pilha1,11);
    printP(pilha1);
    checkPItem(pilha1,11);
    checkPSize(pilha1);
    getIndex(pilha1,11);
    */
    /*
    TFila<int> fila1;
    startF(fila1);
    QueueFila(fila1,2);
    QueueFila(fila1,3);
    QueueFila(fila1,4);
    DeQueue(fila1);
    checkFItem(fila1,3);
    printF(fila1);
    tamanhoDaFila(fila1);
    */

    cout<<"Qual o tamanho do estabelecimento ? forneca o comprimento a largura e a altura do estabelecimento"<<endl;
    float medidaUserC= 25.5;
    float medidaUserL= 13;
    float medidaUserH = 4;

    calculoPrateleira(medidaUserL,medidaUserC);
    produtosNoModulo(medidaUserH);
    calculoEspaco(medidaUserC);
    calculoProdutos(medidaUserL,medidaUserC,medidaUserH);
    calculoProdutos(medidaUserL,medidaUserC,medidaUserH);
    calculoRestoPrateleira(medidaUserC);
    TFila<Cliente> clientes;
     startF(clientes);
    TlistaGenerica<TPilha<Produto>,2000> lista;
    inicializa_lista_generica(lista);
    cout<<"O MAX DE PRODUTOS QUE CABEM NO ARMAZEM SAO: " <<comparaCalculosDosProdutos(medidaUserL,medidaUserC,medidaUserH)<<endl;
    TlistaGenerica<TPilha<Produto>,2000> listaX =  descarregar(medidaUserL,medidaUserC,medidaUserH,lista);
    carregar(listaX,clientes,medidaUserL,medidaUserC,medidaUserH);
    descarregar(medidaUserL,medidaUserC,medidaUserH,listaX);





    return 0;
}
