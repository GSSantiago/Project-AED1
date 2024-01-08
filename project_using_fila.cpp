#include <iostream>
#include <string>	
#include "fila_implementacao.h"
#include "random.h"

#define DEFAULT_AMMO 3


using namespace std;


void Imprimir(Fila* guns){
   Fila FAux;
   string gunName;
   string hexaColor;
   int ammo;
   bool isOkay;


   while(!guns->Vazia()){
     guns->Retira(&gunName, &ammo,&hexaColor, &isOkay);
     FAux.Insere(gunName,ammo,hexaColor,  &isOkay);
     cout << "Cor da Arma:" << gunName << "\n";
     cout << "Municao:" << ammo << "\n";
     cout << "----------------------------------\n";
   }
      while(!FAux.Vazia()){
     FAux.Retira(&gunName, &ammo,&hexaColor, &isOkay);
     guns->Insere(gunName,ammo, hexaColor,  &isOkay);
   }
}

void Disparar(Fila* guns){
   string gunName;
   string hexaColor;
   int ammo;
   bool isOkay;

  guns->DiminuirMunicao(&ammo);

  if(guns->Vazia()) {
    cout << "Nenhuma arma ou bala sobrando\n";
    return;
  }

  if(ammo == 0){
    guns->Retira(&gunName, &ammo, &hexaColor, &isOkay);
     cout << "Arma sem nenhuma bala"<< "\n";

    if(!guns->Vazia())
     cout << "Troca de arma"<< "\n";
  }else{
    cout << guns->ImprimirHexaCor();
    for(int i = ammo; i > 0; i--)
      cout << ">";
    cout << "\x1b[0m" << std::endl;
    cout << ammo << " balas restantes\n";
  } 
}

bool EstaNaFila(Fila* guns, string nomeArma){
  Fila FAux; 
  bool DeuCerto;
  bool estaFila = false;
  string nomeAux, hexaAux;
  int municaoAux = 1;


  while(!guns->Vazia()){
   guns->Retira(&nomeAux, &municaoAux, &hexaAux, &DeuCerto);
   FAux.Insere(nomeAux,municaoAux, hexaAux, &DeuCerto);
   if(nomeAux == nomeArma)
      estaFila = true;
  }
  
    while(!FAux.Vazia()){
   FAux.Retira(&nomeAux, &municaoAux, &hexaAux, &DeuCerto);
   guns->Insere(nomeAux,municaoAux, hexaAux, &DeuCerto);
  }

  return estaFila;

}

void AleatorizarArmas(Fila* guns, Fila* player){
  if(guns->Vazia()){
    Weapon generatedWeapon;
    bool DeuCerto;
    bool estaFila;
    int aux = 0;
    
    while(aux != 4){
     generatedWeapon = GerarArmaAleatoria();

     if(!EstaNaFila(guns, generatedWeapon.corArma)){
      estaFila = !EstaNaFila(player, generatedWeapon.corArma);
      guns->Insere_Prioridade(generatedWeapon.corArma, generatedWeapon.hexaCor, estaFila, &DeuCerto); 
      aux = aux + 1;
      }
    }
  }
}

void SelecionarArmas(Fila* player, Fila* guns){
   if(GerarPorcentagemAleatoria() <= 70)
  {
   char isSelected;
   bool isOk = false;

   string corAux, hexaAux;
   int municaoAux;

   if(guns->Vazia())
      AleatorizarArmas(guns,player);
    
  guns->Retira(&corAux, &municaoAux, &hexaAux, &isOk);
  
   cout << "Uma arma da cor " << corAux << " surgiu, voce deseja pega-la ? Insira o comando E para pegar\n";
   cin >> isSelected;

   if(isSelected == 'e' || isSelected == 'E')
    player->Insere(corAux , DEFAULT_AMMO, hexaAux, &isOk);
  }
}


int main() {
    Fila player;
    Fila guns;
    bool stopWhile = false;
    bool isOK;
    char command;

    string nomeAux, hexaAux;

    player.Insere(Weapons[0].corArma, DEFAULT_AMMO, Weapons[0].hexaCor, &isOK);
    player.Insere(Weapons[1].corArma, DEFAULT_AMMO,Weapons[1].hexaCor, &isOK);

    AleatorizarArmas(&guns,&player);

    while(!stopWhile){
      cout << "Insira um comando: Z para atirar, I para exibir as informacoes das armas e F para interromper" << "\n";
     cin >> command;
     switch (command)
     {
     case 'Z':
     case 'z':
        Disparar(&player);
        SelecionarArmas(&player, &guns);
        break;
     case 'I':
     case 'i':
        Imprimir(&player);
        break;
    case 'F':
    case 'f':
        stopWhile = true;
        break;
     default:
        break;
     }
    }

    return 0;
}