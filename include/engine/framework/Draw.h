#include <shape/Shape.h>
#include <vector>

class Draw {
 public:
  Draw();
  void AddShape(Shape* shape);
  void Triangle();
  void UpdateScreen();
  std::vector<GLfloat> getVertices();

 private:
  std::vector<Shape*> shapes;

  enum Buffer_IDs { ArrayBuffer, NumBuffers };
  enum Attrib_IDs { vPosition = 0 };
  enum VAO_IDs { Triangles, NumVAOs };

  GLuint Buffers[NumBuffers];
  GLuint VAOs[NumVAOs];
  
  const GLuint NumVertices = 6;

  void updateBuffer();
};
