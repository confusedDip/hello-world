#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

#define pi 3.142
double qx, qy, px, py, px1, py1 ,angle;
/* Window re painting handler
needs to be called initially when the window appears first
can be called back anytime whenever repainting is needed
*/

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0,1.0); // sets the bg color, first three parameters are rgb values, last one makes the bg opaque
    glColor3f(0.0, 0.0, 0.0); // sets the color of the picture

    glPointSize(5.0); // sets the point size
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer
    // define shapes enclosed within glBegin and glEnd

    glBegin(GL_LINES);
         glVertex2i(-780, 0);
         glVertex2i(780, 0);
         glEnd();
    glBegin(GL_LINES);
         glVertex2i(0,420);
         glVertex2i(0,-420);
    glEnd();
    glBegin(GL_POINTS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2d(qx, qy);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2d(px, py);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2d(px, py);
    glVertex2d(qx, qy);
    glEnd();
    px1 = px * cos(angle) - py * sin(angle) - qx * cos(angle) + qy * sin(angle) + qx;
    py1 = px * sin(angle) + py * cos(angle) - qx * sin(angle) - qy * cos(angle) + qy;
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2d(px1, py1);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2d(px1, py1);
    glVertex2d(qx, qy);
    glEnd();


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780, 780, -420, 420);
    glFlush(); // Render now
}


int main(int argc, char** argv)
{
    printf("Enter the coordinates of the pivot: ");
    scanf_s("%lf %lf", &qx, &qy);
    printf("Enter the coordinates of the object point: ");
    scanf_s("%lf %lf", &px, &py);
    printf("Enter the angle of rotation: ");
    scanf_s("%lf", &angle);
    angle = (angle * pi) / 180;
    glutInit(&argc, argv); //Initialises the GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(680, 1200);   // Set the window size
    glutInitWindowPosition(0, 0); // Set the window position
    glutCreateWindow("My Window!");  // Creation of window and naming
    myInit();
    glutDisplayFunc(display); // Register display callback handler
    glutMainLoop(); // Event loop
    return 0;
}
