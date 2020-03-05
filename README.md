# ComputerGraphicsGo-
Hail Computer Graphics!

This is a repository for my CG course, and it serve as my git practice as well.

------

#### Lab 1: Draw a national flag!

- Drawing stars: 

  ~~~C++
  void Rotate(double angle, double* X, double* Y) {
  	double lastX = *X, lastY = *Y;
  	*X = lastX * cos(angle) - lastY * sin(angle);
  	*Y = lastX * sin(angle) + lastY * cos(angle);
  }
  ...
  for (int i = 0; i < 5; i++) {
  		glVertex2f((Xvex + S.Xcenter) * Xgrid, (Yvex + S.Ycenter) * Ygrid);
  		glVertex2f((Xcave + S.Xcenter) * Xgrid, (Ycave + S.Ycenter) * Ygrid);
  		Rotate(angle, &Xvex, &Yvex);
  		glVertex2f((Xvex + S.Xcenter) * Xgrid, (Yvex + S.Ycenter) * Ygrid);
  		glVertex2f((Xcave + S.Xcenter) * Xgrid, (Ycave + S.Ycenter) * Ygrid);
  		Rotate(angle, &Xcave, &Ycave);
  	}
  ~~~

  The function *Rotate* uses the rotation matrix.

  Glut Drawing mode: *GL_TRIANGLE_FAN*.

  Stars are defined as a struct:

  ~~~c++
  typedef struct{
  	int Xcenter;
  	int Ycenter;
  	double radius;
  	double angle;
  }STAR;
  ~~~

  to ensure better reusability.

