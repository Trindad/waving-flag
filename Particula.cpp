#include "Particula.hpp"

/**
 * Inicialização
 */
Particula::Particula(Vector3 posicao) : posicao(posicao), posicao_anterior(posicao),aceleracao(Vector3(0,0,0)), massa(1.0f), pode_mover(true), normal_acumulada(Vector3(0,0,0)){}

Particula::Particula(){}

/**
 * Calcula aceleração para adicionar força, 2º lei de Newton
 */
void Particula::adicionaForca(Vector3 f)
{
	aceleracao += f/massa;
}

/**
 * Para a próxima fatia de tempo calcula a próxima posição pela equação:
 * força = ( massa * aceleração ) , o valor é encontrado através do método de
 * verlet.
 */
void Particula::proximoFrame()
{
	if(pode_mover)
	{
		Vector3 temp = posicao;
		posicao = posicao + (posicao - posicao_anterior)*(1.0-RESISTENCIA_AR) + aceleracao*FATIA_DE_TEMPO;
		posicao_anterior = temp;
		aceleracao = Vector3(0,0,0); // reseta aceleração porque a força já foi aplicada
	}
}

Vector3& Particula::getPosicao() {
	return posicao;
}

void Particula::resetaAceleracao() {
	aceleracao = Vector3(0,0,0);
}

void Particula::deslocaPosicao(const Vector3 v) { 
	if(pode_mover) posicao += v;
}

void Particula::fixar() {
	pode_mover = false;
}

void Particula::adicionaNormal(Vector3 normal)
{
	normal_acumulada += normal.normalizado();
}

Vector3& Particula::getNormal() {
 return normal_acumulada;
}

void Particula::resetaNormal() {
	normal_acumulada = Vector3(0,0,0);
}