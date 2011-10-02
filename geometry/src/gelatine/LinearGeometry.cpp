#include "LinearGeometry.h"


namespace gelatine
{


LinearGeometry::LinearGeometry()
{
}


LinearGeometry::~LinearGeometry()
{
}


void
LinearGeometry::render(float alpha, Appearance& appearance)
{
  renderFaces(alpha, appearance);
  renderEdges(alpha, appearance);
}


void
LinearGeometry::renderEdges(float alpha, Appearance& appearance)
{
  glBegin(GL_LINES);
  _register = appearance.getEdgeColor();
  glColor4f(_register[0], _register[1], _register[2],
            _register[3] * alpha * appearance.getModifierAlpha());
  int numberEdges = getNumberEdges();
  float*** edges = getEdges();
  for (int i = 0; i < numberEdges; i++) {
    _register = edges[i][0];
    glVertex3f(_register[0], _register[1], _register[2]);
    _register = edges[i][1];
    glVertex3f(_register[0], _register[1], _register[2]);
  }
  glEnd();
}


void
LinearGeometry::renderFaces(float alpha, Appearance& appearance)
{
  glBegin(GL_TRIANGLES);
  _register = appearance.getFaceColor();
  glColor4f(_register[0], _register[1], _register[2],
            _register[3] * alpha * appearance.getModifierAlpha());
  int number = getNumberTriangles();
  float*** triangles = getTriangles();
  for (int i = 0; i < number; i++) {
    _register = triangles[i][0];
    glVertex3f(_register[0], _register[1], _register[2]);
    _register = triangles[i][1];
    glVertex3f(_register[0], _register[1], _register[2]);
    _register = triangles[i][2];
    glVertex3f(_register[0], _register[1], _register[2]);
  }
  glEnd();

  glBegin(GL_QUADS);
  number = getNumberQuads();
  float*** quads = getQuads();
  for (int i = 0; i < number; i++) {
    _register = quads[i][0];
    glVertex3f(_register[0], _register[1], _register[2]);
    _register = quads[i][1];
    glVertex3f(_register[0], _register[1], _register[2]);
    _register = quads[i][2];
    glVertex3f(_register[0], _register[1], _register[2]);
    _register = quads[i][3];
    glVertex3f(_register[0], _register[1], _register[2]);
  }
  glEnd();

}


}
