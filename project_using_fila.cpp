#include <iostream>
#include <string>	
#include "fila_implementacao.h"
#include "random.h"
#include <thread>

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

void SelecionarArmas(Fila* guns){
   if(GerarPorcentagemAleatoria() <= 70)
  {
   Weapon generatedWeapon;
   char isSelected;
   bool isOk = false;
   generatedWeapon = GerarArmaAleatoria();
   cout << "Uma arma da cor " << generatedWeapon.corArma << " surgiu, voce deseja pega-la ? Insira o comando E para pegar\n";
   cin >> isSelected;

   if(isSelected == 'e' || isSelected == 'E')
    guns->Insere(generatedWeapon.corArma , DEFAULT_AMMO, generatedWeapon.hexaCor, &isOk);
  }
}


int main() {
    Fila guns;
    bool stopWhile = false;
    bool isOK;
    char command;

    guns.Insere(Weapons[0].corArma, DEFAULT_AMMO, Weapons[0].hexaCor, &isOK);
    guns.Insere(Weapons[1].corArma, DEFAULT_AMMO,Weapons[1].hexaCor, &isOK);

    while(!stopWhile){
      cout << "Insira um comando: Z para atirar, I para exibir as informacoes das armas e F para interromper" << "\n";
     cin >> command;
     switch (command)
     {
     case 'Z':
     case 'z':
        Disparar(&guns);
        SelecionarArmas(&guns);
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