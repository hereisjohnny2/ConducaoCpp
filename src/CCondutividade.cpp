#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include "CCondutividade.hpp"

namespace fs = std::filesystem;

using namespace std;

CCondutividade::CCondutividade(const std::string &_nomeCaminho)
{
    AtualizaListaMaterial(_nomeCaminho);
}

void CCondutividade::AdicionaMaterial(std::ostream &os, std::istream &in)
{
    os << "Digite o nome do novo material: ";
    string novoMaterial;
    in >> novoMaterial;

    std::ofstream file("../data/" + novoMaterial + ".dat");

    double x, y;
    if (file.is_open())
    {
        do
        {
            os << "Digite os valores de X e Y do ponto : ";
            in >> x >> y;
            in.get();
            if (in.good())
            {
                file << x << "\t" << y << "\n";
            }
        } while (std::cin.good());

        in.clear();
        os << std::endl;
    }
    file.close();

    AtualizaListaMaterial("../data");
}

void CCondutividade::AtualizaListaMaterial(const std::string &_nomeCaminho)
{
    data.clear();
    for (const auto &material : fs::directory_iterator(_nomeCaminho))
        data[material.path().stem()] = make_shared<CInterpolacao>(string(material.path()));
}