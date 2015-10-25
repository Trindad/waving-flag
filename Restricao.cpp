#include "Restricao.hpp"

/**
 * Constrói a restrição
 * Para que particulas se mantenham em uma grade
 * Mesmo as particulas sendo corrigidas, devido aos movimentos
 * e outras restrições a bandeira não volta no estado inicial
 * em um primeiro momento.
 */
Restricao::Restricao(Particula *p1, Particula *p2) :  p1(p1),p2(p2)
{
	Vector3 vec = p1->getPosicao() - p2->getPosicao();
	distancia = vec.magnitude();
}

/**
 * Uma restrição entre duas particulas é solucionada
 * Esse método é chamado pela classe Tecido
 */
void Restricao::satisfazerRestricao()
{
	Vector3 p1_a_p2 = p2->getPosicao() - p1->getPosicao(); // vetor de distância entre p1 e p2
	float distancia_atual = p1_a_p2.magnitude(); // distância/magnitude atual entre p1 e p2
	
	Vector3 correcao = p1_a_p2 * (1.0f - distancia/distancia_atual); // O vetor de deslocamento que poderia mover p1 para a distância padrão de p2
	Vector3 metade = correcao * 0.5f; // divide ao meio vetor de correção para aplicar em p1 e p2
	
	/**
	 * Desloca p1 e p2 em direção contrária
	 * Usando o vetor metade.
	 */
	p1->deslocaPosicao(metade);
	p2->deslocaPosicao(-metade); 
}