#include <GL/glut.h>
#include <cstdlib>
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);/* white background */
	glColor3f(1.0, 0.0, 0.0); /* red paint */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	// vertices of triangle
	GLfloat vertices[3][2] = { { 0.0, 0.0 },{ 25.0, 50.0 },{ 50.0, 0.0 } };
	
	int pointsNum,midPoint;
	int rand();
	// triangle inside point
	GLfloat p[2] = { 7.5, 5.0 };
	glClear(GL_COLOR_BUFFER_BIT); // clear paint window
	glBegin(GL_POINTS);
	// 5000 points
	for (pointsNum = 0; pointsNum < 50000; pointsNum++)
	{
		midPoint = rand() % 3;
		// middle
		p[0] = (p[0] + vertices[midPoint][0]) / 2.0;
		p[1] = (p[1] + vertices[midPoint][1]) / 2.0;
		glVertex2fv(p);
	}
	glEnd();
	glFlush(); 
}
int main(int argc, char *argv[])
{
	// initialize 
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sierpinski Ê¾Àý£¬DATE:2015.1.3");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

}