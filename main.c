/* 
 *** Компиляция под Windows (компилятор MinGW)
 * 
 * Укажите путь к библиотеке glut и укажите ссылку компилятору
 * gcc -Wall -o "%e" "%f" -lopengl32 -lglu32 -I"%d/include" -L"%d/lib" -lglut32
 *
 * 
 *** Компиляция под linux 
 * 
 * установите библиотеки opengl: 
 *     sudo apt-get install mesa-common-dev
 * 
 * Это установит необходимые инструменты для сборки из исходного кода.
 *     sudo apt-get install build-essential
 * 
 * установите freeglut
 *     sudo apt-get install freeglut3-dev
 * 
 * После чего команда сборки будет выглядеть
 *     gcc -Wall -o "%e" "%f" -lGL -lGLU -lglut
 * 
 *** Удачи!
*/

#include <GL/gl.h>
// Для widows
#include "glut.h"

// Для linux
//#include "GL/glut.h"

typedef struct {
	int x;
	int y;
} Delta;

Delta delta;
int step = 50;

void keyPressed (unsigned char key, int x, int y) {  
	
	//if (key == 'a') { 
	//	Do something
	//}  

	switch(key) {
		case 'w':
			delta.y +=step;
			break;
		case 's':
			delta.y -=step;
			break;
		case 'a':
			delta.x -=step;
			break;
		case 'd':
			delta.x +=step;
			break;
	}
	
}  

// Для обраотки клавишь стрелок
void arrow_keys ( int key, int x, int y )   
{
  switch(key) {
		case GLUT_KEY_UP:
			delta.y +=step;
			break;
		case GLUT_KEY_DOWN:
			delta.y -=step;
			break;
		case GLUT_KEY_LEFT:
			delta.x -=step;
			break;
		case GLUT_KEY_RIGHT:
			delta.x +=step;
			break;
	}
}



void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//
	// ВАШ КОД ЗДЕСЬ
	//
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(250 + delta.x, 450 + delta.y);
	
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(250 + delta.x, 150 + delta.y);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(550 + delta.x, 150 + delta.y);
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550 + delta.x, 400 + delta.y);
	glEnd();
	
	//
	// КОНЕЦ
	//
	glutSwapBuffers();
}


int main (int argc, char * argv[])
{ 
	delta.x = 0;
	delta.y = 0;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL my first program");
	
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	
	// Для работы анимации
	glutIdleFunc( display );
	// Обработчик нажатия клавишь
	glutKeyboardFunc(keyPressed);
	
	// Включить возможность ловить клавиши
	glutSpecialFunc( arrow_keys );
	
	glutMainLoop();
	
	return 0;
}
