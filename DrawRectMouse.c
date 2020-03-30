#include<GL/glut.h>
#include<stdio.h>
int x1,y1,x2,y2,i=1;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
}

void mouse(int button, int state, int mousex, int mousey)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (i == 1)
		{
			x1 = mousex - 767;
			y1 = 395 - mousey;
			i++;
		}
		else if (i == 2)
		{
			x2 = mousex - 767;
			y2 = 395 - mousey;
			i++;
		}
		printf("%d %d\n", mousex, mousey);
		
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		printf("Right Click!\n");
		i = 1;
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);
		if(i==2)
			glVertex2i(x1, y1);
		if (i == 3)
			glVertex2i(x2, y2);
		glEnd();
	if (i == 3) {
		glBegin(GL_POLYGON);
		glVertex2i(x1, y1);
		glVertex2i(x1, y2);

		//glVertex2i(x1, y2);
		glVertex2i(x2, y2);

		//glVertex2i(x2, y2);
		glVertex2i(x2, y1);

		//glVertex2i(x2, y1);
		glVertex2i(x1, y1);
		glEnd();
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-767, 767, -395, 395);
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1534, 790 );
	glutCreateWindow("My Window");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
