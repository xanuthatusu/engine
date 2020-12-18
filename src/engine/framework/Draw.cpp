#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <engine/framework/Draw.h>

#include <iostream>
#include <thread>
#include <chrono>

namespace Framework {

void Draw::AddShape(Shape* shape) {
  std::cout << "adding shape!\n";
  
  shapes.push_back(shape);
}

void Draw::UpdateScreen() {
  static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  static const float red[] = { 1.0f, 0.0f, 0.0f, 0.0f };

  glClearBufferfv(GL_COLOR, 0, black);

  int numVerts = updateBuffer();

  //std::cout << "drawing " << numVerts << " vertices" << std::endl;
  
  glBindVertexArray(VAOs[Triangles]);
  glDrawArrays(GL_TRIANGLES, 0, numVerts);

  glFlush();
}

int Draw::updateBuffer() {
  glBindVertexArray(VAOs[Triangles]);

  std::vector<GLfloat> vertices = getVertices();

  if (vertices.size() == 0) {
    std::cout << "0 vertices recieved!\n";
    return 0;
  }

  glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_DYNAMIC_DRAW);

  glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, 0);
  glEnableVertexAttribArray(vPosition);

  return vertices.size() / 2;
}

Draw::Draw() {
  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray(VAOs[Triangles]);

  glGenBuffers(NumBuffers, Buffers);

  updateBuffer();
}

std::vector<GLfloat> Draw::getVertices() {
  std::vector<GLfloat> glVerts;

  if (shapes.size() == 0) {
    //std::cout << "shapes.size() is empty\n";
    return glVerts;
  }
  
  std::vector<Shape*>::iterator shapeIt;
  for (shapeIt = shapes.begin(); shapeIt != shapes.end(); shapeIt++) {
    Shape* shape = *shapeIt;
    std::vector<GLfloat> v = shape->GetVertices();
    glVerts.insert(glVerts.end(), v.begin(), v.end());
  }

  return glVerts;
}

}
