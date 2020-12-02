#ifndef CCONDUTIVIDADE
#define CCONDUTIVIDADE

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>

#include "../libs/InterLin/src/CInterpolacao.hpp"

class CCondutividade
{
private:
    std::map<std::string, std::shared_ptr<CInterpolacao>> data; ///> Conjunto de Dados entre os Materiais e as Curvas de Interpolação

public:
    /// Construtor Padrão
    CCondutividade() = default;
    /// Construtor sobrecarregado para a inclusão de dados a partir de um arquivo do disco.
    CCondutividade(const std::string &_nomeCaminho);
    /// Construtor de Cópia
    CCondutividade(CCondutividade &obj) : data(obj.data) {}
    /// Destrutor Padrão
    ~CCondutividade() = default;

    std::map<std::string, std::shared_ptr<CInterpolacao>> Data() { return data; }
    void Data(std::map<std::string, std::shared_ptr<CInterpolacao>> _data) { data = _data; }

    /// Adiciona uma material solicitando o nome e os dados de temperatura e condutividade
    void AdicionaMaterial(std::ostream &os = std::cout, std::istream &in = std::cin);

    /// Limpa o mapa e le novamente o diretório com os arquivos dos materiais
    void AtualizaListaMaterial(const std::string &_nomeCaminho);

    /// Sobrecarrega o operador de acesso [] para retornar a csua curva correspondente.
    std::shared_ptr<CInterpolacao> operator[](const std::string &_material) { return data[_material]; }
};

#endif // !CCONDUTIVIDADE