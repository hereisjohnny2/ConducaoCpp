#ifndef CFFLUXOCALOR
#define CFLUXOCALOR

#include <functional>
#include <iostream>
#include <string>
#include <memory>

// Bibliotecas do Projeto
#include "../libs/InterLin/src/CInterpolacao.hpp"

/// Objeto função para o calculo do fluxo de calor por condução unidimensional em uma placa plana para materiais isotrópicos.
class CFluxoCalor
{
private:
    double dx{1.0};                        ///> Espessura da Placa (m)
    double dt{1.0};                        ///> Intervalo de Temperatura (°C)
    double t0{100.0};                      ///> Temperatura Inicial do Corpo (°C)
    double q{1.0};                         ///> Fluxo de Calor Unidimensional (W/m²)
    double k{1.0};                         ///> Condutividade Térmica (W/°C.m)
    std::shared_ptr<CInterpolacao> curvaK; ///> Curva de Condutividade Térmica
    std::string material;                  ///> Nome do Material

public:
    /// Construtor Padrão.
    CFluxoCalor() = default;
    /// Construtor sobrecarregado para entrar com o nome do material. A curva de condutividade é calculada.
    CFluxoCalor(std::string _material, std::shared_ptr<CInterpolacao> _curvaK) : curvaK(_curvaK), material(_material) {}

    /// Construtor de Copia
    CFluxoCalor(CFluxoCalor &obj) : dx(obj.dx), dt(obj.dt), t0(obj.t0), q(obj.q), k(obj.k), curvaK(obj.curvaK), material(obj.material) {}
    /// Destrutor
    ~CFluxoCalor() = default;

    /// Getters & Setters
    double Dx() const { return dx; }
    void Dx(double &_dx) { dx = _dx; }

    double Dt() const { return dt; }
    void Dt(double &_dt) { dt = _dt; }

    double T0() const { return t0; }
    void T0(double &_t0) { t0 = _t0; }

    double Q() const { return q; }
    void Q(double &_q) { q = _q; }

    double K() const { return k; }
    void K(double &_k) { k = _k; }

    std::shared_ptr<CInterpolacao> CurvaK() { return curvaK; }
    void CurvaK(std::shared_ptr<CInterpolacao> _curvaK) { curvaK = _curvaK; }

    std::string Material() const { return material; }
    void Material(std::string &_material) { material = _material; }

    /// Calculo do fluxo de calor com a condutividade termica calculada a partir da curva de interpolação.
    double CalculaFluxoCalor(double &_t0, double &_dx, double &_dt);
    /// Sobrecarga do operador (). Torna a classe um objeto função.
    double operator()(double _t0, double _dx, double _dt) { return CalculaFluxoCalor(_t0, _dx, _dt); }
};

#endif // !CFFLUXOCALOR