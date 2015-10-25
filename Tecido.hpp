#include "Restricao.hpp"

class Tecido
{
private:

	int largura; // largura da bandeira em relação ao número de particulas
	int altura; // altura da bandeira  em relação ao número de particulas
	std::vector<Particula> particulas; // vetor de todas as particulas do tecido
	std::vector<Restricao> restricoes; // vetor de todas as restrições do tecido

	Particula* getParticula(int, int);
	void constroiRestricao(Particula *, Particula *);
	Vector3 calculaNormalDoTriangulo(Particula *,Particula *,Particula *);
	void adicionaForcaDoVentoTriangulo(Particula *,Particula *,Particula *, const Vector3);
	void desenhaTriangulo(Particula *, Particula *, Particula *, const Vector3);

public:

	Tecido(float, float, int, int);
	void adicionaForca(const Vector3);
	void vento(const Vector3);
	Vector3 getCor(int);
	void proximoFrame();
	void desenha();
};