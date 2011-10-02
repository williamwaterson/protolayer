#include "Surface.h"


namespace gelatine
{


namespace
{
  ControlPointFactory controlPointFactory;
}


Surface::Surface(int m, int n) :
  ::protolayer::Surface(m, n, controlPointFactory) //  ::protolayer::Surface(m, n, controlPointFactory)
{
}


Surface::Surface(int m, int n, float*** positions) :
  ::protolayer::Surface(m, n, positions, controlPointFactory)
{
}


Surface::~Surface()
{
}


void
Surface::renderMeshes(float alpha, Appearance& appearance)
{
  /*
  glColor4f(0.0, 0.0, 0.0, 1.0f);
  glPointSize(4.0);
  glBegin(GL_POINTS);
  ControlPointIteratorType iter = getControlPoints();
  ControlPointIteratorType end = getLastControlPoint();
  for (int i = 0; i < getNumberPointsM() * getNumberPointsN(); i++) {
    glVertex3fv(&(getRawPoints()[i*4]));
  }
  glEnd();

  //  glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &(getRawPoints[0][0][0]));
  glMap2f(GL_MAP2_VERTEX_3,
          0, 1, 4, getNumberPointsM(),
          0, 1, getNumberPointsM() * 4, getNumberPointsN(),
          getRawPoints());

  glColor4f(0.0, 0.0, 0.0, 1.0);
  for (int j = 0; j <= 8; j++) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 30; i++) {
      glEvalCoord2f((GLfloat) i/30.0, (GLfloat) j/8.0);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 30; i++) {
      glEvalCoord2f((GLfloat) j/8.0, (GLfloat) i/30.0);
    }
    glEnd();
  }
  */
}


void
Surface::renderMeshesInSelectionMode(float alpha, Appearance& appearance)
{
  renderFaces(alpha, appearance);
}


void
Surface::renderFaces(float alpha, Appearance& appearance)
{
  /*
  //  glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &_meshPoints[0][0][0]);
  glMap2f(GL_MAP2_VERTEX_3,
          0, 1, 4, getNumberPointsM(),
          0, 1, getNumberPointsM() * 4, getNumberPointsN(),
          getRawPoints());

  glColor4f(0.5, 0.5, 0.5, 0.7);
  glMapGrid2f(30, 0.0, 1.0, 30, 0.0, 1.0);
  glEvalMesh2(GL_FILL, 0, 30, 0, 30);
  */
}


void
Surface::renderFacesInSelectionMode(float alpha, Appearance& appearance)
{
  renderFaces(alpha, appearance);
}


*/

}
