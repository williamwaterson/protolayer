#ifndef GELATINE_FORWARD_H
#define GELATINE_FORWARD_H

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <GLUT/glut.h>
  #include <AGL/agl.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

/** TODO: Documentation */
namespace gelatine
{

/** Forward declarations */
class Group;
class Scene;
class Shot;
class Space;
class SpaceView;

}


#endif // GELATINE_FORWARD_H
