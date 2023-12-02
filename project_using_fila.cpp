#include <iostream>
#include <string>	
#include "fila_implementacao.h"

using namespace std;

void Imprimir(Fila* guns){
   Fila FAux;
   string gunName;
   int ammo;
   bool isOkay;


   while(!guns->Vazia()){
     guns->Retira(&gunName, &ammo, &isOkay);
     FAux.Insere(gunName,ammo,  &isOkay);
     cout << "Nome da Arma:" << gunName << "\n";
     cout << "Municao:" << ammo << "\n";
     cout << "----------------------------------";
   }
      while(!FAux.Vazia()){
     FAux.Retira(&gunName, &ammo, &isOkay);
     guns->Insere(gunName,ammo,  &isOkay);
   }
}

void Disparar(Fila* guns){
   string gunName;
   int ammo;
   bool isOkay;

  guns->DiminuirMunicao(&ammo);

  if(guns->Vazia()) {
    cout << "Nenhuma arma ou bala sobrando\n";
    return;
  }

  if(ammo == 0){
    guns->Retira(&gunName, &ammo, &isOkay);
     cout << "Arma sem nenhuma bala"<< "\n";

    if(!guns->Vazia())
     cout << "Troca de arma"<< "\n";
  }else
    cout << ammo << " balas restantes\n";
  
}

int main() {
    Fila guns;
    bool stopWhile = false;
    bool isOKay;
    char command;

    guns.Insere("Vermelha", 3, &isOKay);
    guns.Insere("Azul", 3, &isOKay);


    while(!stopWhile){
      cout << "Insira um comando: Z para atirar, I para exibir as informacoes das armas e F para interromper" << "\n";
     cin >> command;
     switch (command)
     {
     case 'Z':
     case 'z':
        Disparar(&guns);
        break;
     case 'I':
     case 'i':
        Imprimir(&guns);
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