#ifndef __SHAPE__
#define __SHAPE__

#include <GLFW/glfw3.h>

class Shape {
 public:
  Shape(GLuint numVertices): numVertices(numVertices) {};
  void SetVertices(GLuint numVertices, GLfloat vertices[][2]);
 private:
  GLuint numVertices;
  GLfloat vertices[][2];
};

#endif // __SHAPE__
