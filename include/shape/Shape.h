#ifndef __SHAPE__
#define __SHAPE__

#include <GLFW/glfw3.h>

#include <vector>

typedef struct {
  float x, y;
} Vertex;

enum ShapeType { TRIANGLE, RECT };

class Shape {
 public:
  Shape() {};
  Shape(ShapeType t, std::vector<Vertex> v) : type{t}, vertices{v} {};
  std::vector<GLfloat> GetVertices();

 private:
  ShapeType type;
  std::vector<Vertex> vertices;
};

#endif // __SHAPE__
