#include <string>	

using namespace std;

struct NodeFila {
  string NomeArma;
  int Municao;
  string HexaCor;
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
        void Insere(string,int, string, bool*);
        void Insere_Prioridade(string,string,bool, bool*);
        void Retira(string*, int*, string*, bool*);
        void DiminuirMunicao(int *x);
        string ImprimirHexaCor();
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

      void Fila::Insere(string x, int y, string z, bool *DeuCerto){
            if(Cheia() == 1){
              *DeuCerto = false;
              return;
            }
            NodeFila* FAux;
            FAux = CreateNode();
            FAux->Municao = y;
            FAux->NomeArma = x;
            FAux->HexaCor = z;

            if(Vazia() == true){
              Header.Next = FAux;
            }

            Ultimo->Next = FAux;
            Ultimo = FAux;
            
            *DeuCerto = true;
          }

     void Fila::Retira(string *x, int *y, string *z, bool *DeuCerto){
   
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
          *z = FAux->HexaCor;
          DeleteNode(FAux);


           *DeuCerto = true;
        }
      
      void Fila::DiminuirMunicao(int* x){
        if(Header.Next->Municao != 0)
          Header.Next->Municao--;
        
        *x = Header.Next->Municao;

      }

      string Fila::ImprimirHexaCor(){
        if(!Vazia())
          return Header.Next->HexaCor;
        return "";
      }

    void Fila::Insere_Prioridade(string x, string y, bool Prioridade, bool *DeuCerto){
          if(Cheia() == true){
            *DeuCerto = false;
            return;
          }
          NodeFila* FAux;
          FAux = CreateNode();
          FAux->NomeArma = x;
          FAux->HexaCor = y;

          if(Vazia() == true){
            Header.Next = FAux;
            Ultimo = FAux;
          }else {

          //Se essa inserção possuir prioridade ela será inserida no inicio da fila
          if(Prioridade){
           FAux->Next = Header.Next;
           Header.Next = FAux;
          }
          else{
           Ultimo->Next = FAux;
           Ultimo = FAux;
         }
         }
          
          *DeuCerto = true;
        }





