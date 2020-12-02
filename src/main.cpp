#include <iostream>

/// Bibliotecas Externas
#include "../libs/InterLin/src/CInterpolacao.hpp"

// Classes Principais do Projeto
#include "CCondutividade.hpp"
#include "CFluxoCalor.hpp"

using namespace std;

void ArguardarEnter();

int main(int argc, char const *argv[])
{
    cout << "*****************************************************************************************\n";
    cout << "*************                                                                ************\n";
    cout << "*************       Fluxo de Calor por Condução Unidimensional - Demo        ************\n";
    cout << "*************                                                                ************\n";
    cout << "*****************************************************************************************\n\n";

    // Carregando um novo conjunto de dados
    string path = "../data";
    CCondutividade listaK(path);

    // Criando um objeto para o calculo de fluxo de calor em um material
    CFluxoCalor fluxPb("chumbo", listaK["chumbo"]);
    std::cout << "Fluxo de Calor no " << fluxPb.Material() << " a 300°C = " << fluxPb(300.0, 1.5, 50.0) << " W/°C.m" << std::endl;

    // Acionando um novo material à lista
    listaK.AdicionaMaterial(std::cout, std::cin);

    // Calculando o Fluxo de Calor no novo material
    CFluxoCalor fluxAco("aco", listaK["aco"]);
    std::cout << "Fluxo de Calor no " << fluxAco.Material() << " a 255°C = " << fluxAco(255.0, 1.5, 50.0) << " W/°C.m" << std::endl;

    ArguardarEnter();
}

void ArguardarEnter()
{
    std::cout << std::endl
              << "Pressione ENTER para continuar..." << std::endl;
    std::cin.clear();                              // Zera estado de cin
    std::cin.ignore(std::cin.rdbuf()->in_avail()); // Ignora
    std::cin.get();
}
