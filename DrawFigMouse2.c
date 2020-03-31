#include<GL/glut.h>
#include<math.h>
#define pi 3.142
double a[500], b[500], c, d;
int i=0;
double x, y,r;
void mouse(int button, int state, int mousex, int mousey)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		a[i] = mousex;
		b[i] = 600 - mousey;
		i = (i + 1) % 500;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		/*glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);*/
		if(i>0)
			i--;
	}
	glutPostRedisplay();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POINTS);
	for (int j = 0; j < i; j++)
	{
		glVertex2d(a[j], b[j]);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int j = 1; j < i; j++)
	{
		glVertex2d(a[j], b[j]);
		glVertex2d(a[j - 1], b[j - 1]);
	}
	glEnd();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);

	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Click and Draw");
	glClearColor(1, 1, 1, 1);
	glColor3i(1, 0, 0);
	glPointSize(5);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
