#include "glut.h"
#include <iostream>	//������
#include <math.h>
using namespace std;

#define PI 3.141692654

typedef struct{
	int Xcenter;
	int Ycenter;
	double radius;
	double angle;
}STAR;	

//��ȡ��������е���ת�������
void Rotate(double angle, double* X, double* Y) {
	double lastX = *X, lastY = *Y;
	*X = lastX * cos(angle) - lastY * sin(angle);
	*Y = lastX * sin(angle) + lastY * cos(angle);
}

void DrawStars( STAR S )
{
	//X��Y����
	double Xgrid = 1.0 / 15;
	double Ygrid = 1.0 / 10;
	//����Ǽ������
	double Xvex = 0, Yvex = S.radius;
	//����ǰ��ݴ�����
	double Xcave = 0, Ycave = S.radius * 0.4;
	//������ת����
	double angle = 72.0 / 180.0 * PI;

	//��ʼ��ת����֤С����Ǽ��׼�����������
	Rotate(S.angle, &Xvex, &Yvex);
	Rotate(S.angle, &Xcave, &Ycave);
	Rotate(angle / 2, &Xcave, &Ycave);

	//ʹ��GL_TRIANGLE_FANģʽ��ͼ
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);	//��ɫ
	glVertex2f(S.Xcenter * Xgrid, S.Ycenter * Ygrid);	//ȷ�����ĵ�

	//ѭ�����������
	for (int i = 0; i < 5; i++) {
		glVertex2f((Xvex + S.Xcenter) * Xgrid, (Yvex + S.Ycenter) * Ygrid);
		glVertex2f((Xcave + S.Xcenter) * Xgrid, (Ycave + S.Ycenter) * Ygrid);
		Rotate(angle, &Xvex, &Yvex);
		glVertex2f((Xvex + S.Xcenter) * Xgrid, (Yvex + S.Ycenter) * Ygrid);
		glVertex2f((Xcave + S.Xcenter) * Xgrid, (Ycave + S.Ycenter) * Ygrid);
		Rotate(angle, &Xcave, &Ycave);
	}
	glEnd();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex3f(-1.0, 1.0, 0.5);
	glVertex3f(1.0, 1.0, 0.5);
	glVertex3f(1.0, -1.0, 0.5);
	glVertex3f(-1.0, -1.0, 0.5);
	glEnd();
	
	//�������ǵ�����λ�á��뾶����ʼ��ת�Ƕ�
	STAR stars[5] = {
		{-10, 5, 3.0, 0.0}, 
		{-5, 8, 1.0, 0.86217},
		{-3, 6, 1.0, 0.46365},
		{-3, 3, 1.0, 0.0},
		{-5, 1, 1.0, -0.32175}
	};
	//ѭ�����������
	for (int i = 0; i < 5; i++) {
		DrawStars(stars[i]);
	}

	glutSwapBuffers();
}

int main (int argc,  char *argv[])
{
	glutInit(&argc,argv);
	//GLUT initialization
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	//double buffering, RGB color mode
	glutInitWindowPosition(50, 50);
	//initialize location for the upper-left corner of the display window
	glutInitWindowSize(300, 200);
	//set the initial pixel width and height of the display window
	glutCreateWindow("Simple GLUT App");
	//Create a window with a caption sent in as a parameter
	glutDisplayFunc(Display);
	//specify what to display
	glutMainLoop();
	//activate the display window and its graphic content
	//must be the last function
	return 0;
}