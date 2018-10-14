/*
 * Disciplina: Construção de Software Gráfico 3D
 * Professor: Luiz Antônio Pavão
 * Aluno: João Pedro Rodrigues de Lima
 */

#include <Windows.h>
#include <GL\freeglut.h>
#include "VectorClass.cpp"

 // VARIÁVEIS GLOBAIS
char title[] = "BOUCING BOX - Open GL - João Pedro Lima";
GLdouble range = 200.0;
GLdouble angle = 0.0;
GLdouble keyAngle = 0.0; // ângulo para a câmera

double edgeCube = 40.0; // aresta do cubo

Vector position(0.0, 0.0, 0.0); // vetor posição (baseado no arquivo do processing)
Vector velocity(1.5, 2.1, 1.0); // vetor velocidade (baseado no arquivo do processing)
Vector gravity(0.0, -0.5, 0.0); // vetor gravidade (baseado no arquivo do processing)

// FUNÇÕES DE DESENHO

// Função Cubo (main - cubo animado, BlackBoard)
/* mudança dos parâmetros e métodos (de float para double) */
void cubo(double edge) 
{
	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3d(1.0, 0.0, 0.0); // red
	glVertex3d(-(edge / 2), edge / 2, edge / 2);
	glVertex3d(-(edge / 2), -(edge / 2), edge / 2);

	glColor3d(0.0, 0.0, 1.0); // blue
	glVertex3d(edge / 2, edge / 2, edge / 2);
	glVertex3d(edge / 2, -edge / 2, edge / 2);

	glColor3d(1.0, 1.0, 1.0); // white
	glVertex3d(edge / 2, edge / 2, -(edge / 2));
	glVertex3d(edge / 2, -(edge / 2), -(edge / 2));

	glColor3d(1.0, 1.0, 0.0); // magenta
	glVertex3d(-(edge / 2), edge / 2, -(edge / 2));
	glVertex3d(-(edge / 2), -(edge / 2), -(edge / 2));

	glColor3d(1.0, 0.0, 1.0); // cyan
	glVertex3d(-(edge / 2), edge / 2, edge / 2);
	glVertex3d(-(edge / 2), -(edge / 2), edge / 2);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glColor3d(0.5, 0.5, 0.0); // grey
	glVertex3d(-(edge / 2), edge / 2, -(edge / 2));
	glVertex3d(-(edge / 2), edge / 2, edge / 2);
	glVertex3d(edge / 2, edge / 2, -(edge / 2));
	glVertex3d(edge / 2, edge / 2, edge / 2);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glColor3d(1.0, 0.5, 0.9); // orange
	glVertex3d(edge / 2, -(edge / 2), -(edge / 2));
	glVertex3d(edge / 2, -(edge / 2), edge / 2);
	glVertex3d(-(edge / 2), -(edge / 2), -(edge / 2));
	glVertex3d(-(edge / 2), -(edge / 2), edge / 2);

	glEnd();
}

// Função Cubo Alternativa (posição como parâmetro)
/* cores basedas em https://www.tug.org/pracjourn/2007-4/walden/color.pdf */
void cubo(double a, double xPosition, double yPosition, double zPosition)  
{
	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3d(1.0, 0.0, 0.0); // red
	glVertex3d(-(a / 2) + xPosition, (a / 2) + yPosition, (a / 2) + zPosition);
	glVertex3d(-(a / 2) + xPosition, -(a / 2) + yPosition, (a / 2) + zPosition);

	glColor3d(0.0, 0.1, 0.4); // azul marinho
	glVertex3d((a / 2) + xPosition, (a / 2) + yPosition, (a / 2) + zPosition);
	glVertex3d((a / 2) + xPosition, -(a / 2) + yPosition, (a / 2) + zPosition);

	glColor3d(0.0, 0.3, 0.2); // verde escuro
	glVertex3d((a / 2) + xPosition, (a / 2) + yPosition, -(a / 2) + zPosition);
	glVertex3d((a / 2) + xPosition, -(a / 2) + yPosition, -(a / 2) + zPosition);

	glColor3d(0.3, 0.1, 0.5); // roxo
	glVertex3d(-(a / 2) + xPosition, (a / 2) + yPosition, -(a / 2) + zPosition);
	glVertex3d(-(a / 2) + xPosition, -(a / 2) + yPosition, -(a / 2) + zPosition);

	glColor3d(0.6, 0.0, 0.4); // rosa esucro
	glVertex3d(-(a / 2) + xPosition, (a / 2) + yPosition, (a / 2) + zPosition);
	glVertex3d(-(a / 2) + xPosition, -(a / 2) + yPosition, (a / 2) + zPosition);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glColor3d(0.2, 0.6, 0.6); // verde água
	glVertex3d(-(a / 2) + xPosition, (a / 2) + yPosition, -(a / 2) + zPosition);
	glVertex3d(-(a / 2) + xPosition, (a / 2) + yPosition, (a / 2) + zPosition);
	glVertex3d((a / 2) + xPosition, (a / 2) + yPosition, -(a / 2) + zPosition);
	glVertex3d((a / 2) + xPosition, (a / 2) + yPosition, (a / 2) + zPosition);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glColor3d(0.5, 0.1, 0.2); // magenta
	glVertex3d((a / 2) + xPosition, -(a / 2) + yPosition, -(a / 2) + zPosition);
	glVertex3d((a / 2) + xPosition, -(a / 2) + yPosition, (a / 2) + zPosition);
	glVertex3d(-(a / 2) + xPosition, -(a / 2) + yPosition, -(a / 2) + zPosition);
	glVertex3d(-(a / 2) + xPosition, -(a / 2) + yPosition, (a / 2) + zPosition);

	glEnd();
}

void updatePosition(int value)
{
	position.vectorSum(velocity); // soma vetor de velocidade com o de posição
	velocity.vectorSum(gravity); // soma vetor de gravidade com o de velocidade
	
	// atualizar posição de acordo com o arquivo do processing
	
	if ((position.xCoord > range - edgeCube) || (position.xCoord < -range + edgeCube)) // bounce off edges
	{
		velocity.xCoord = velocity.xCoord * -1;
	}

	if ((position.yCoord > range - edgeCube) || (position.yCoord < -range + edgeCube)) // reducing velocity
	{
		velocity.yCoord = velocity.yCoord * -0.95;
		position.yCoord = -range + edgeCube;
	}

	if ((position.zCoord > range - edgeCube) || (position.zCoord < -range + edgeCube))
	{
		velocity.zCoord = velocity.zCoord * -1;
	}

	glutPostRedisplay(); 
	glutTimerFunc(25, updatePosition, 0); // atualizar a cada 25 ms
}

// Função Telas do Teclado (main - controle de câmera pelo teclado, BlackBoard)
void processSpecialKeys(int key, int xx, int yy)
{
	switch (key) {
	case (GLUT_KEY_LEFT):
		keyAngle--;
		break;
	case (GLUT_KEY_RIGHT):
		keyAngle++;
		break;
	case (GLUT_KEY_UP):
		angle--;
		break;
	case (GLUT_KEY_DOWN):
		angle++;
		break;
	}
}

// OpenGL Gráficos
void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // RGBA, argumentos são floats
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);  
	glDepthFunc(GL_LEQUAL);   
	glShadeModel(GL_SMOOTH);  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}

void render() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // limpar as cores
	glMatrixMode(GL_MODELVIEW);    
	glLoadIdentity();                  // resetar

	glRotated(angle, 1.0, 0.0, 0.0);
	glRotated(keyAngle, 0.0, 1.0, 0.0);
	
	glColor3d(1.0, 1.0, 1.0); // ROTATE F => ROTATE D
	glutWireCube(1.8*range);

	cubo(edgeCube, position.xCoord, position.yCoord, position.zCoord);

	glutSwapBuffers();  
}

void reshape(GLsizei w, GLsizei h) 
{
	if (h == 0)
	{
		h = 1;
	}

	// dimensões
	glViewport(0, 0, w, h);

	// sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
	{
		glOrtho(-range, range, -range * h / w, range*h / w, -range * 2, range * 2);
	}
	else 
	{
		glOrtho(-range * w / h, range*w / h, -range, range, -range * 2, range * 2);
	}
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);            
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowSize(640, 480);   
	glutInitWindowPosition(50, 50); 
	glutCreateWindow(title);          
	glutDisplayFunc(render);      
	glutReshapeFunc(reshape);     
	initGL();                       
	glutIdleFunc(render);			  
	glutSpecialFunc(processSpecialKeys);  
	glutTimerFunc(25, updatePosition, 0);
	glutMainLoop();    

	return 0;
}
