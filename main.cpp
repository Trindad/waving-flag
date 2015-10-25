/**
 * *********************************************************
 * Trabalho 2: Bandeira 
 *
 * Descrição: Desenhar bandeira de  Cuba utilizando primitivas
 *
 * Alunos: Silvana Trindade e Maurício André Cinelli
 * *********************************************************
 */
#include <GL/glut.h>

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bandeira");
	glutDisplayFunc(draw);

	glutMainLoop();
	return 0;
}
