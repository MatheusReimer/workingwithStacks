#ifndef FUNCOES_H
#define FUNCOES_H
#include <ctime>
#include <cstdlib>
#include "filas.h"
#include "pilhas.h"
#include "Structs.h"
#include "generica.h"

int vezesQueRodouDescarregamento=0;
int vezesQueRodouCarregamento=0;



int calculoRestoPrateleira(float medidaUserC){
    int colunasDePrateleiras = medidaUserC/5.5;

    float restoC =  medidaUserC - (colunasDePrateleiras *5.5);

    int espacosNaPrateleira = 0;
    if(restoC>1.8 && restoC<2.7){
        //incluir prateileira de 2 pilhas(espacos)
        espacosNaPrateleira = 2;
    }
    if(restoC>=2.7 && restoC<3.6){
        //incluir prateleira de 3 pilhas(espacos)
        espacosNaPrateleira =3;

    }
    if(restoC>=3.6 && restoC<4.5){
        //incluir prateleira de 4 pilhas(espacos)
        espacosNaPrateleira=4;

    }
    if(restoC>=4.5 && restoC<5.4){
        //incluir prateleira de 5 pilhas(espacos)
        espacosNaPrateleira = 5;


    }
    return espacosNaPrateleira;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








int calculoPrateleira(float medidaUserL, float medidaUserC){
    int prateleirasParalelas = medidaUserL/1.5;
    int colunasDePrateleiras = medidaUserC/5.5;
    if(calculoRestoPrateleira(medidaUserC)>0){
        colunasDePrateleiras ++;
    }

    int resultadoPrateleiras = colunasDePrateleiras * prateleirasParalelas;
    //cout<<"Prateleiras:   "<<resultadoPrateleiras<<endl;
    return resultadoPrateleiras;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculoEspaco(float medidaUserC){
    int resultadoEspaco = (medidaUserC/5.5);
    resultadoEspaco = resultadoEspaco * 6;
    int prateleiraAdicional = calculoRestoPrateleira(medidaUserC);
    resultadoEspaco= resultadoEspaco+ prateleiraAdicional;
    if(resultadoEspaco<=2){
        cout<<"Nao pode ser feito uma prateleira com menos de 2 espacos"<<endl;
        resultadoEspaco=0;
    }

    //cout<<"Espacos:   "<<resultadoEspaco<<endl;

    return resultadoEspaco;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int produtosNoModulo(int medidaUserH){
    int resultadoModulos;
    if(medidaUserH>=3 && medidaUserH<=3.9){
        resultadoModulos=9;
    }
    else if(medidaUserH>3.9){
        resultadoModulos=12;
    }
    else{
        cout<<"Nao cabe nenhuma prateleira com essa altura"<<endl;
        resultadoModulos=0;
    }
    //cout<<"Modulos:   "<<resultadoModulos<<endl;
    return resultadoModulos;
}

int numeroDeModulos(int medidaUserH){
    int resultadoModulos;
    if(medidaUserH>=3 && medidaUserH<=3.9){
        resultadoModulos=2;
    }
    else if(medidaUserH>3.9){
        resultadoModulos=3;
    }
    else{
        cout<<"Nao cabe nenhuma prateleira com essa altura"<<endl;
        resultadoModulos=0;
    }
    //cout<<"Modulos:   "<<resultadoModulos<<endl;
    return resultadoModulos;
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculoProdutos(int medidaUserL,int medidaUserC,int medidaUserH){

        //6 COLUNAS * QUANTIDADE DE PRODUTOS QUE PODEM SER COLOCADOS NA PILHA * QUANTIDADE DE PRATELEIRAS
       /// QUANTIDADE DE COLUNAS * QUANTIDADE DE ALTURA
        int produtos;
        int prateleirasParalelas = medidaUserL/1.5;
        ///Calculo espaço ja contem a prateleira
        produtos = calculoEspaco(medidaUserC)* produtosNoModulo(medidaUserH)* prateleirasParalelas ;
        //cout<<"Total de produtos:    "<<produtos<<endl;
        return produtos;


}










//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int calculoProdutos2(int medidaUserL,int medidaUserC,int medidaUserH){

        //6 COLUNAS * QUANTIDADE DE PRODUTOS QUE PODEM SER COLOCADOS NA PILHA * QUANTIDADE DE PRATELEIRAS
        int produtos=0;

        //cout<<"Total de produtos2:    "<<produtos<<endl;

        int prateleirasParalelas = medidaUserC/1.5;
        produtos = calculoEspaco(medidaUserL)* produtosNoModulo(medidaUserH)* prateleirasParalelas ;
        return produtos;

}












//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int comparaCalculosDosProdutos(int medidaUserL,int medidaUserC,int medidaUserH){
        if( calculoProdutos(medidaUserL,medidaUserC,medidaUserH)>calculoProdutos2(medidaUserL,medidaUserC,medidaUserH)){
            int produtoFinal = calculoProdutos(medidaUserL,medidaUserC,medidaUserH);
         //   cout<<"Total de produtos que podem ser armazenados:    "<<produtoFinal<<endl;
            return produtoFinal;
        }
       else{
            int produtoFinal = calculoProdutos2(medidaUserL,medidaUserC,medidaUserH);
          //  cout<<"Total de produtos que podem ser armazenados:    "<<produtoFinal<<endl;
            return produtoFinal;
        }

}









//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int criandoNumeroRandomico(int medidaUserL,int medidaUserC,int medidaUserH){

    //CRIANDO NUMERO RANDOMICO
    int cabemXprodutos = comparaCalculosDosProdutos(medidaUserL,medidaUserC,medidaUserH);
    int dezPorcento = cabemXprodutos * 0.10;
    int quinhentosPorcento = cabemXprodutos * 5;
    int diferenca = quinhentosPorcento-dezPorcento;
    srand(time(NULL));
    int produtosChegando=0;
    for(int j=0;j<100;j++){
     produtosChegando = rand() % diferenca + dezPorcento;
    }
    produtosChegando = 300;
    if(produtosChegando>cabemXprodutos){
        cout<<"ALERTA!, nao ha espaco no armazem para a quantidade de produtos que esta chegando"<<endl;
        return 0;
    }else{
        //cout<<produtosChegando<<endl;
    }


    cout<<"Estao chegando "<<produtosChegando<<" produtos no caminhao"<<endl;
    if(produtosChegando>cabemXprodutos){
        cout<<"ALERTA!, nao ha espaco no armazem para a quantidade de produtos que esta chegando"<<endl;

    }
    return produtosChegando;
}












//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int regulandoTempo(int contadorTempo,int empilhadeira,int contadorProdutos){
    int contadorTempoEmMinutos = contadorTempo;

    //300 minutos = 5horas
    while(contadorTempoEmMinutos>=300){
        empilhadeira++;
        contadorTempoEmMinutos = contadorTempoEmMinutos/empilhadeira;
    }



    cout<<contadorTempoEmMinutos<<" Minutos  "<< "para empilhar os "<<contadorProdutos<<" produtos utilizando "<<empilhadeira<<" empilhadeiras"<<endl;

}





////PARA SABER AS PILHAS QUE TEM ESPAÇO PRA COLOCAR( TEM DESFALQUE)
int  checandoAsPilhas(TlistaGenerica<TPilha<Produto>,2000>lista){
     int contador =0;
     int temp=0;
     int anterior=0;
      for(int i=0;i<lista.quantidade;i++){

        if(contador==2  && contador>0){
        return anterior;
        }
        if( temp==contador && contador>0){
            ///COLOCANDO -2 PARA APRESENTAR O ANTERIOR AO ANTERIOR
            anterior= lista.elementos[i].dado.topo->dado.pilha;
           anterior = anterior-2;
           return anterior;
        }
        temp=contador;
        //quantidade elementos na pilha
        contador=0;



        while(lista.elementos[i].dado.topo !=NULL){
            contador ++;
            anterior = lista.elementos[i].dado.topo->dado.pilha;
            lista.elementos[i].dado.topo= lista.elementos[i].dado.topo->proximo;

        }
    }
     anterior=0;
     return anterior;

}


int  pilhasComEspaco(TlistaGenerica<TPilha<Produto>,2000>lista){
    int contador =0;
    int temp=0;
    int anterior=0;
    int contadorPilhas=0;
     for(int i=0;i<lista.quantidade;i++){

       if(contador==2  && contador>0){
       contadorPilhas++;
       }
       if( temp==contador && contador>0){
           ///COLOCANDO -2 PARA APRESENTAR O ANTERIOR AO ANTERIOR
           anterior= lista.elementos[i].dado.topo->dado.pilha;
          anterior = anterior-2;

          contadorPilhas++;
       }
       temp=contador;
       //quantidade elementos na pilha
       contador=0;



       while(lista.elementos[i].dado.topo !=NULL){
           contador ++;
           anterior = lista.elementos[i].dado.topo->dado.pilha;
           lista.elementos[i].dado.topo= lista.elementos[i].dado.topo->proximo;

       }
   }
    return contadorPilhas;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int somadorDeProdutos(int medidaUserL, int medidaUserC,int medidaUserH,int contador){

    for (int i=0;i<comparaCalculosDosProdutos(medidaUserL,medidaUserC,medidaUserH);i++){
        contador++;
        return contador;
    }

}

int codigoUltimoElemento(TlistaGenerica<TPilha<Produto>,2000> lista){
   int codigoUltimo=0;
    for(int i=0;i<lista.quantidade;i++){
       while(lista.elementos[i].dado.topo!=NULL){

           codigoUltimo= lista.elementos[i].dado.topo->dado.codigo;
           lista.elementos[i].dado.topo= lista.elementos[i].dado.topo->proximo;
           if(i==lista.quantidade-1 && lista.elementos[i].dado.topo->proximo->proximo==NULL){
            return codigoUltimo;
           }
        }
    }

}
int verificandoQuantidadeNaPilha(TlistaGenerica<TPilha<Produto>,2000> lista, int pilha){

    int produtosNaPilha=0;
        while(lista.elementos[pilha].dado.topo!=NULL){

           produtosNaPilha++;
            lista.elementos[pilha].dado.topo= lista.elementos[pilha].dado.topo->proximo;
        }

        return produtosNaPilha;
    }

   void insereNasLacunas(TlistaGenerica<TPilha<Produto>,2000>& lista, int pos,Produto& teste){


       push(lista.elementos[pos].dado,teste);


        }

   int gerenciaEspaco( int medidaUserL, int medidaUserC,int medidaUserH, int valorAdicionar, int valorRetirar){
   int produtosMax = comparaCalculosDosProdutos(medidaUserL,medidaUserC,medidaUserH);
   produtosMax = produtosMax - valorRetirar;
   produtosMax= produtosMax+ valorAdicionar;
   return produtosMax;

   }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TlistaGenerica<TPilha<Produto>,2000>  descarregar( int medidaUserL, int medidaUserC,int medidaUserH,TlistaGenerica<TPilha<Produto>,2000>& lista){
    int produtosChegando =criandoNumeroRandomico(medidaUserL,medidaUserC,medidaUserH);
    vezesQueRodouDescarregamento++;
        if(gerenciaEspaco(medidaUserL,medidaUserC,medidaUserH,0,produtosChegando)<0){
            cout<<"PROBLEMA NO ARMAZENAMENTO NA: "<<vezesQueRodouDescarregamento<<" VEZ QUE O PROGRAMA DESCARREGOU"<<endl;

        }

    int quantidadeDeEspacos = produtosChegando/produtosNoModulo(medidaUserH);
    cout<<"Serao necessarias "<<quantidadeDeEspacos<<" espacos para armazenar esta quantidade de produtos"<<endl;

    //criando uma fila de pilhas
    TPilha<Produto> pilha;
    Produto teste;
    int contadorProdutos=0;
    int descobreModulo=0;
    int contadorTempo=0;
    int empilhadeira=1;
    int contadorDePilhas=0;
    descobreModulo = produtosNoModulo(medidaUserH);
    int descobreModulo2= numeroDeModulos(medidaUserH);
    //PEGA O ULTIMO CODIGO QUE EXISTE PARA NÃO RESETAR O CODIGO E NAO TER 2 PRODUTOS COM O MESMO CODIGO
    teste.codigo=codigoUltimoElemento(lista);


    ///Quando um produto for retirado, abre espaco pra entrar outro produto naquele lugar
   for(int i =0;i<=pilhasComEspaco(lista);i++){

    teste.codigo++;
    teste.modulos= verificandoQuantidadeNaPilha(lista,checandoAsPilhas(lista)+1);
    if(teste.modulos==3){
         contadorTempo=contadorTempo+13;
    }
    if(teste.modulos==4){
         contadorTempo=contadorTempo+12;
    }
    if(teste.modulos==5){
         contadorTempo=contadorTempo+11;
    }
    teste.pilha = pilhasComEspaco(lista);
    insereNasLacunas(lista,checandoAsPilhas(lista),teste);

}
    ///INTRODUZINDO NA PILHA
    for(int i=0;i<quantidadeDeEspacos;i++){

        for(int j=0;j<descobreModulo2;j++){
            startP(pilha);
            teste.pilha=contadorDePilhas;

            if(j==0){
                for(int k=0;k<5;k++){

                contadorProdutos++;
                teste.codigo++;
                teste.modulos=1;
                push(pilha,teste);

                }
            }
            if(j==1){
                for(int k=0;k<4;k++){

                contadorProdutos++;
                teste.codigo++;
                teste.modulos=2;
                push(pilha,teste);
                contadorTempo=contadorTempo+12;

                }
            }

            if(j==2){
                for(int k=0;k<3;k++){

                contadorProdutos++;
               teste.codigo++;
                teste.modulos=3;

                push(pilha,teste);
                contadorTempo=contadorTempo+13;
                }
            }
            contadorDePilhas++;
            inserir_fim_lista_generica(lista,pilha);

            }



            }



            regulandoTempo(contadorTempo,empilhadeira,contadorProdutos);
            imprimir_lista_generica(lista);



    return lista;

}


int funcaoDeRetirada(TlistaGenerica<TPilha<Produto>,2000> lista,int valorDoCodigo ){
    //RODANDO A LISTA DE PILHAS E CADA PILHA INDIVIDUALMENTE


    for(int i=0;i<lista.quantidade;i++){

        while(lista.elementos[i].dado.topo !=NULL){
            if(lista.elementos[i].dado.topo->dado.codigo==valorDoCodigo ){
                //cout<<"O Elemento de codigo  '"<< lista.elementos[i].dado.topo->dado.codigo<<"'  se encontra na pilha "<<lista.elementos[i].dado.topo->dado.pilha<<endl;
                //RETORNANDO EM QUE PILHA DA LISTA ELE ENCONTROU O ELEMENTO
                return i;




            }
            lista.elementos[i].dado.topo= lista.elementos[i].dado.topo->proximo;
        }
    }

}


int checandoQtdeElementos(TlistaGenerica<TPilha<Produto>,2000> lista,int valorDoCodigo ){
    //RODANDO A LISTA DE PILHAS E CADA PILHA INDIVIDUALMENTE

    ///A IDEIA É CONTAR QUANTOS ELEMENTOS TEM NA PILHA E PASSAR PARA A FUNCAO CARREGAR, LÁ CHECAR IF==3,IF==4,IF==5
    int pilhaDoElemento = funcaoDeRetirada(lista,valorDoCodigo);
    int somadorTempo=0;
        while(lista.elementos[pilhaDoElemento].dado.topo !=NULL){

            somadorTempo++;
            lista.elementos[pilhaDoElemento].dado.topo= lista.elementos[pilhaDoElemento].dado.topo->proximo;
        }

       return somadorTempo;
}

int gerandoCodigosUsuario(TlistaGenerica<TPilha<Produto>,2000> lista){
    ///USA 1 PRA CONTAR QUANTOS PRODUTOS TEM
  int somadorTempo=0;
    for(int i=0;i<lista.quantidade;i++){

        while(lista.elementos[i].dado.topo!=NULL){

            lista.elementos[i].dado.topo=lista.elementos[i].dado.topo->proximo;
            somadorTempo++;
        }
    }


    int randomNumber = 0;
    srand(time(NULL));
    for(int j=0;j<17;j++){
     randomNumber = rand() % somadorTempo+1;
    }

    return randomNumber;
}




///CADA CARREGAR FUNCIONA PARA UM CLIENTE;
void carregar(TlistaGenerica<TPilha<Produto>,2000>& lista,TFila<Cliente> clientes , int medidaUserL, int medidaUserC,int medidaUserH){
    //CRIANDO CLIENTE PARA TESTE

    //GERANDO UM NUMERO ENTRE UM 10 PARA SABER QUANTOS PRODUTOS O USUARIO COMPROU(MAIORIA 1)
    int qtdeProdutosComprados = 10;
     srand(time(NULL));
     int resultadoProdutosComprados=0;
     for(int j=0;j<27;j++){
        resultadoProdutosComprados = rand() % qtdeProdutosComprados +1;
    }
    cout<<"Escolhendo um numero de 1 a 10 para randomizar quantos produtos o usuario vai pegar:" << resultadoProdutosComprados<<endl;

    //TESTANDO CODIGOS
    int codigo = 0;
    int codigo2 = 0;
    int codigo3 = 0;
     int tempoCliente=0;
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///
     ///                                                        CASO O CLIENTE COMPRE 1 PRODUTO

    if(resultadoProdutosComprados<=5){
       codigo = gerandoCodigosUsuario(lista);
       cout<<"O(s) produto(s) que o usuario ira comprar tem o codigo: "<<codigo<<endl;
       tempoCliente= checandoQtdeElementos(lista,codigo)+3;

       Cliente numero1;
       numero1.codigoProduto1=codigo;
       //CLIENTE COLOCADO NA FILA
       QueueFila(clientes,numero1);

       int resultadoDoSearch1 = funcaoDeRetirada(lista,codigo);

       cout<<"O tempo para a entrega do produto ao cliente sera de:  "<<tempoCliente<<" minutos"<<endl;
       //POP
       if(lista.quantidade<2){
           cout<<"A Pilha nao pode ter menos de 2 elementos"<<endl;
       }
        lista.elementos[resultadoDoSearch1].dado.topo = lista.elementos[resultadoDoSearch1].dado.topo->proximo;
        gerenciaEspaco(medidaUserL,medidaUserC,medidaUserH,0,1);
        DeQueue(clientes);
    }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///                                                           PARA CLIENTES COM 2 PRODUTOS
    if(resultadoProdutosComprados>5 && resultadoProdutosComprados<9){
           while(codigo == codigo2 || codigo==codigo3 || codigo2==codigo3){

        codigo = gerandoCodigosUsuario(lista);
        codigo2 =gerandoCodigosUsuario(lista);
           }
        cout<<"O(s) produto(s) que o usuario ira comprar tem o codigo: "<<codigo<<"  ,  "<< codigo2<<endl;
         tempoCliente= checandoQtdeElementos(lista,codigo)+3+checandoQtdeElementos(lista,codigo2)+3;

         Cliente numero1;
         numero1.codigoProduto1=codigo;
         numero1.codigoProduto2 =codigo2;
         //CLIENTE COLOCADO NA FILA
         QueueFila(clientes,numero1);

         int resultadoDoSearch1 = funcaoDeRetirada(lista,codigo);
         int resultadoDoSearch2= funcaoDeRetirada(lista,codigo2);

         cout<<"O tempo para a entrega do produto ao cliente sera de:  "<<tempoCliente<<" minutos"<<endl;
         //POP
         if(lista.quantidade<2){
             cout<<"A Pilha nao pode ter menos de 2 elementos"<<endl;
         }
          lista.elementos[resultadoDoSearch1].dado.topo = lista.elementos[resultadoDoSearch1].dado.topo->proximo;
          lista.elementos[resultadoDoSearch2].dado.topo = lista.elementos[resultadoDoSearch2].dado.topo->proximo;
          gerenciaEspaco(medidaUserL,medidaUserC,medidaUserH,0,2);
          DeQueue(clientes);

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                         PARA CLIENTES COM 3 PRODUTOS
    if(resultadoProdutosComprados>8 && resultadoProdutosComprados<=10) {
    codigo=gerandoCodigosUsuario(lista);
        while(codigo == codigo2 || codigo==codigo3 || codigo2==codigo3 ){

     codigo2 = gerandoCodigosUsuario(lista);
     codigo3=gerandoCodigosUsuario(lista);
        }

     cout<<"O(s) produto(s) que o usuario ira comprar tem o codigo: "<<codigo<<"  ,  "<< codigo2<<"  ,  "<< codigo3<<endl;
      tempoCliente= checandoQtdeElementos(lista,codigo)+3+checandoQtdeElementos(lista,codigo2)+3 +checandoQtdeElementos(lista,codigo3)+3;

      Cliente numero1;
      numero1.codigoProduto1=codigo;
      numero1.codigoProduto2 =codigo2;
      numero1.codigoProduto3=codigo3;
      //CLIENTE COLOCADO NA FILA
      QueueFila(clientes,numero1);

      int resultadoDoSearch1 = funcaoDeRetirada(lista,codigo);
      int resultadoDoSearch2= funcaoDeRetirada(lista,codigo2);
      int resultadoDoSearch3 = funcaoDeRetirada(lista,codigo3);
      cout<<"O tempo para a entrega do produto ao cliente sera de:  "<<tempoCliente<<" minutos"<<endl;
      //POP
      if(lista.quantidade<2){
          cout<<"A Pilha nao pode ter menos de 2 elementos"<<endl;
      }
       lista.elementos[resultadoDoSearch1].dado.topo = lista.elementos[resultadoDoSearch1].dado.topo->proximo;
       lista.elementos[resultadoDoSearch2].dado.topo = lista.elementos[resultadoDoSearch2].dado.topo->proximo;
       lista.elementos[resultadoDoSearch3].dado.topo = lista.elementos[resultadoDoSearch3].dado.topo->proximo;
       gerenciaEspaco(medidaUserL,medidaUserC,medidaUserH,0,3);
       DeQueue(clientes);
    }



    /////////////////////////////////////////////////////////////////////////
    ///
    ///PRINTANDO COMO FICOU A LISTA APÓS A REMOÇAO
}



#endif // FUNCOES_H
