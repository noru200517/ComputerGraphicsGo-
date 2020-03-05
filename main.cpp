#include "glut.h"
#include <iostream>	//测试用
#include <math.h>
using namespace std;

#define PI 3.141692654

typedef struct{
	int Xcenter;
	int Ycenter;
	double radius;
	double angle;
}STAR;	

//获取绕五角星中点旋转后的坐标
void Rotate(double angle, double* X, double* Y) {
	double lastX = *X, lastY = *Y;
	*X = lastX * cos(angle) - lastY * sin(angle);
	*Y = lastX * sin(angle) + lastY * cos(angle);
}

void DrawStars( STAR S )
{
	//X、Y步长
	double Xgrid = 1.0 / 15;
	double Ygrid = 1.0 / 10;
	//五角星尖端坐标
	double Xvex = 0, Yvex = S.radius;
	//五角星凹陷处坐标
	double Xcave = 0, Ycave = S.radius * 0.4;
	//单次旋转弧度
	double angle = 72.0 / 180.0 * PI;

	//初始旋转，保证小五角星尖对准大五角星中心
	Rotate(S.angle, &Xvex, &Yvex);
	Rotate(S.angle, &Xcave, &Ycave);
	Rotate(angle / 2, &Xcave, &Ycave);

	//使用GL_TRIANGLE_FAN模式绘图
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);	//黄色
	glVertex2f(S.Xcenter * Xgrid, S.Ycenter * Ygrid);	//确定中心点

	//循环绘制五角星
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
	
	//五颗五角星的中心位置、半径及初始旋转角度
	STAR stars[5] = {
		{-10, 5, 3.0, 0.0}, 
		{-5, 8, 1.0, 0.86217},
		{-3, 6, 1.0, 0.46365},
		{-3, 3, 1.0, 0.0},
		{-5, 1, 1.0, -0.32175}
	};
	//循环绘制五颗星
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