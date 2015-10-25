#ifndef RESTRICAO_H
#define RESTRICAO_H

#include "Particula.hpp"

class Restricao
{
private:
	float distancia; // distância padrão entre p1 e p2
public:

	Particula *p1, *p2; // particulas que estão conectadas nesta restrição

	Restricao(Particula *, Particula *);
	void satisfazerRestricao();
};

#endif