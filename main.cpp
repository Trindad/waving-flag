/**
 * *********************************************************
 * Trabalho 2: Bandeira
 *
 * Descrição: Desenhar bandeira de Wallis e Fortuna e bandeira de Israel
 * por malha de triângulos, usando simulação de tecido
 *
 * Alunos: Silvana Trindade e Maurício André Cinelli
 * *********************************************************
 */
#include "Tecido.hpp"

// Tecido bandeira(14,10,110,60); // inicia configurações da bandeira  Israel
Tecido bandeira(14,10,60,60); // inicia configurações da bandeira  Wallis e Fortuna

void init()
{
	/**
	 * Efeitos de iluminação
	 */
	glClearColor(0.2f, 0.2f, 0.4f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_LIGHT0);
	GLfloat lightPos[4] = {-1.0,1.0,0.5,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,(GLfloat *) &lightPos);

	glEnable(GL_LIGHT1);

	GLfloat lightAmbient1[4] = {0.0,0.0,0.0,0.0};
	GLfloat lightPos1[4] = {1.0,0.0,-0.2,0.0};
	GLfloat lightDiffuse1[4] = {0.5,0.5,0.3,0.0};

	glLightfv(GL_LIGHT1,GL_POSITION,(GLfloat *) &lightPos1);
	glLightfv(GL_LIGHT1,GL_AMBIENT,(GLfloat *) &lightAmbient1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,(GLfloat *) &lightDiffuse1);

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
}

/**
 * Função chamada para cada frame
 */
void display(void)
{

	// calculando posições
	bandeira.adicionaForca(Vector3(0,-0.2,0)*FATIA_DE_TEMPO); // adiciona a gravidade
	bandeira.vento(Vector3(4,0,0.1)*FATIA_DE_TEMPO); // adiciona vento, quanto maior o valor mais forte será o vento
	bandeira.proximoFrame(); // Calcula posições das particulas para esse frame

	// desenha
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/**
	 * Pôr-do-Sol:
	 * Faz o gradiente do plano de fundo
	 * Pinta os dois pontos de baixo de laranja
	 * e os pontos superiores de azul, desabilita
	 * a luz para não ter sombra, faz a interpolação
	 * das cores formando o gradiente
	 */
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1,182.0f/255.0f,0);//laranja
	glVertex3f(-300.0f,-300.0f,-200.0f);
	glVertex3f(200.0f,-100.0f,-100.0f);
	glColor3f(160/255.0f, 176/255.0f, 255/255.0f);//azul escuro
	glVertex3f(300.0f,100.0f,-100.0f);
	glVertex3f(-200.0f,100.0f,-100.0f);
	glEnd();
	glEnable(GL_LIGHTING);

	/**
	 * Habilita anti-serrilhado
	 */
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(-6.5,6,-9.0f); // move a camera para o centro da bandeira
	bandeira.desenha(); // desenha o tecido/bandeira

	/**
	 * Desenha o mastro utilizando um cilindro
	 * Faz as translação e rotação necessária
	 */
	glColor3f(0.8,0.8,0.8);
	glPushMatrix();
	glRotatef(90,1,0,0);
	glTranslatef(0,-5.8,-0.5);
	gluCylinder(gluNewQuadric(),0.15,0.15,19,200,300);
	glPopMatrix();

	/**
	 * Desenha argolas que seguram a bandeira
	 * Faz as operações de transformação 
	 */
	glColor3f(0.8,0.8,0.8);
	glPushMatrix();
	glTranslatef(0.04,-9.7,-5.8);
	glRotatef(90,1,0,0);
	glRotatef(180,0,0,1);
	glRotatef(180,1,0,0);
	glScalef(0.2, 0.2, 0.15);
	glutSolidTorus(0.5,0.5,100,100);
	glPopMatrix();


	glColor3f(0.8,0.8,0.8);
	glPushMatrix();
	glTranslatef(0.04,-0.1,-5.8);
	glRotatef(90,1,0,0);
	glRotatef(180,0,0,1);
	glRotatef(180,1,0,0);
	glScalef(0.2, 0.2, 0.15);
	glutSolidTorus(0.5,0.5,100,100);
	glPopMatrix();


	/**
	 * Bola do topo do mastro da bandeira
	 */
	glPushMatrix();
	glTranslatef(-0.03,0.8,-5.9);
	gluSphere(gluNewQuadric(),0.27,32,32);
	glPopMatrix();



	glutSwapBuffers();
	glutPostRedisplay();
}

/**
 * Configurações da janela de visualização
 */
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective (80,( float )w /( float )h,0.8,5000.0 );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main ( int argc, char** argv )
{
	glutInit( &argc, argv );

	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 480 );

	glutCreateWindow( "Bandeira" );
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
}
