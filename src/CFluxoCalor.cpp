#include "CFluxoCalor.hpp"

using namespace std;

double CFluxoCalor::CalculaFluxoCalor(double &_T0, double &_dx, double &_dt)
{
    return q = -(*curvaK)(_T0)*_dt / _dx;
}