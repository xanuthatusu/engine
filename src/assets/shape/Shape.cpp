#include <assets/shape/Shape.h>

std::vector<GLfloat> Shape::GetVertices() {
  std::vector<GLfloat> glVerts;
  
  std::vector<Vertex>::iterator vertIt;
  for (vertIt = vertices.begin(); vertIt != vertices.end(); vertIt++) {
    Vertex v = *vertIt;
    glVerts.push_back((GLfloat)v.x);
    glVerts.push_back((GLfloat)v.y);
  }

  return glVerts;
}
