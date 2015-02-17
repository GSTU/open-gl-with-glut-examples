// команда сборки проекта для geany
// компилятор mingw
// gcc -Wall -o "%e" "%f" -lopengl32 -lglu32 -I"%d/include" -L"%d/lib" -lglut32

#include <GL/gl.h>
#include "glut.h"

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
	glClear(GL_COLOR_BUFFER_BIT);
	
	//
	// ВАШ КОД ЗДЕСЬ
	//
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(250, 450);
	
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(250, 150);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(550, 150);
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550, 400);
	glEnd();
	
	//
	// КОНЕЦ
	//
	glutSwapBuffers();
}

int main (int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL my first program");
	
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	
	glutMainLoop();
	
	return 0;
}
