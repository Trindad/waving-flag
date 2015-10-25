#ifndef PARTICULA_H
#define PARTICULA_H

#include "Vector3.hpp"


#define RESISTENCIA_AR 0.01 // o valor da resistência do ar, quanto maior menos a bandeira se movimenta, ou seja, mais rápido vai desacelerar
#define FATIA_DE_TEMPO 0.5*0.5

class Particula
{
private:

	bool pode_mover;

	float massa; // massa da particula
	Vector3 posicao;
	Vector3 posicao_anterior; // posição anterior da partícula, utilizada pelo método de Verlet
	Vector3 aceleracao; // aceleração atual da partícula
	Vector3 normal_acumulada; // normal acumulada, para fazer o sombreamento

public:
	
	Particula(Vector3);
	Particula();
	void adicionaForca(Vector3);
	void proximoFrame();
	Vector3& getPosicao();
	void resetaAceleracao();
	void deslocaPosicao(const Vector3);
	void fixar();
	void adicionaNormal(Vector3);
	Vector3& getNormal();
	void resetaNormal();
};

#endif
