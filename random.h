#include <iostream>
#include <cstdlib>
#include <ctime>

struct Weapon{
    string corArma;
    string hexaCor;
};

Weapon Weapons[] = {
{"Vermelho","\x1b[41m\x1b[37m"}, 
{"Azul", "\x1b[44m\x1b[37m"}, 
{"Roxo", "\x1b[45m\x1b[37m"}, 
{"Amarelo", "\x1b[43m\x1b[30m"}};


int GerarPorcentagemAleatoria(){
    unsigned seed = time(0);

    srand(seed);

    return (1+rand()%100);
}

Weapon GerarArmaAleatoria(){
    
     unsigned seed = time(0);

    srand(seed);

    return Weapons[rand()%4];
}