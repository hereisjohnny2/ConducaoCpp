#include "CReta.hpp"

void CReta::Entrada(std::ostream &os, std::istream &in)
{
    os << "Entre com o valor de a e b: ";
    in >> a >> b;
    os << CReta::Equacao() << "\n";
}

void CReta::Entrada(std::string nomeArquivo)
{
    std::ifstream fin(nomeArquivo);
    if (!fin)
    {
        std::cerr << "Não foi possível abrir o arquivo!\n";
        exit(1);
    }
    fin >> a >> b;
    fin.close();
}

void CReta::Saida(std::ostream &os) const
{
    os << "y = " << std::setw(10) << a << " + " << std::setw(10) << b << "*x";
}

std::string CReta::Equacao() const
{
    std::ostringstream os;
    Saida(os);
    return os.str();
}

void CReta::Saida(std::string nomeArquivo)
{
    std::ofstream fout(nomeArquivo);
    if (!fout)
    {
        std::cerr << "Não foi possível abrir o arquivo!\n";
        exit(1);
    }
    fout << a << "\t" << b;
    fout.close();
}

std::ostream &operator<<(std::ostream &os, const CReta &reta)
{
    os << reta.a << "\t" << reta.b;
    return os;
}

std::istream &operator>>(std::istream &in, CReta &reta)
{
    in >> reta.a >> reta.b;
    return in;
}

bool operator==(const CReta &reta1, const CReta &reta2)
{
    return (reta1.a == reta2.a and reta1.b == reta2.b);
}

bool operator!=(const CReta &reta1, const CReta &reta2)
{
    return !(reta1 == reta2);
}

// void CReta::Plot(CGnuplot &grafico) const
// {
//     std::vector<double> vx{0.0, 1.0};
//     std::vector<double> vy{Fx(0.0), Fx(1.0)};

//     grafico.PlotVector(vx, vy, Equacao());
// }

// CGnuplot &operator<<(CGnuplot &grafico, const CReta &reta)
// {
//     reta.Plot(grafico);
//     return grafico;
// }
