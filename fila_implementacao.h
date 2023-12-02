#include <string>	

using namespace std;

struct NodeFila {
  string NomeArma;
  int Municao;
  NodeFila* Next = NULL;
};

class Fila {
    private: 
        NodeFila Header;
        NodeFila* Ultimo;

        NodeFila* CreateNode();
        void DeleteNode(NodeFila*);

    public:
        Fila();
        bool Vazia();
        bool Cheia();
        void Insere(string,int, bool*);
        void Retira(string*, int*, bool*);
        void DiminuirMunicao(int *x);
};

      Fila::Fila(){
          Ultimo = &Header;
      }

      NodeFila* Fila::CreateNode() {
       return new NodeFila;
      }

      void Fila::DeleteNode(NodeFila* node){
         delete node;
      }

     bool Fila::Vazia(){ 
        if(&Header == Ultimo)
           return true;
        else return false;
      }

     bool Fila::Cheia() {
            return false;
        }

     void Fila::Insere(string x, int y, bool *DeuCerto){
          if(Cheia() == 1){
            *DeuCerto = false;
            return;
          }
          NodeFila* FAux;
          FAux = CreateNode();
          FAux->Municao = y;
          FAux->NomeArma = x;

          if(Vazia() == true){
            Header.Next = FAux;
          }

          Ultimo->Next = FAux;
          Ultimo = FAux;
          
          *DeuCerto = true;
        }

     void Fila::Retira(string *x, int *y, bool *DeuCerto){
   
            if(Vazia() == 1){
            *DeuCerto = false;
            return;
          }

          NodeFila *FAux;
          FAux = Header.Next;
          
          if(FAux == Ultimo){
           Ultimo = &Header;
          }
          else{
           Header.Next = FAux->Next;
          }

          *x = FAux->NomeArma;
          *y = FAux->Municao;
          DeleteNode(FAux);


           *DeuCerto = true;
        }
      
      void Fila::DiminuirMunicao(int* x){
        if(Header.Next->Municao != 0)
          Header.Next->Municao--;
        
        *x = Header.Next->Municao;

      }






