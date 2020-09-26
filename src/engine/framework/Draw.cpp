#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <engine/framework/Draw.h>

#include <iostream>

void Draw::AddShape(Shape* shape) {
  shapes.push_back(shape);
}

void Draw::UpdateScreen() {
  static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  static const float red[] = { 1.0f, 0.0f, 0.0f, 0.0f };

  std::vector<GLfloat> vertices = getVertices();

  glClearBufferfv(GL_COLOR, 0, black);

  glBindVertexArray(VAOs[Triangles]);
  glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 2);

  glFlush();
}

Draw::Draw() {
  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray(VAOs[Triangles]);

  std::vector<GLfloat> vertices = getVertices();

  glGenBuffers(NumBuffers, Buffers);
  glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, 0);
  glEnableVertexAttribArray(vPosition);
}

std::vector<GLfloat> Draw::getVertices() {
  std::vector<GLfloat> vertices;

  GLfloat v = 0.5f;
  vertices.push_back(v);
  v = 0.1f;
  vertices.push_back(v);
  v = -0.1f;
  vertices.push_back(v);
  v = -0.7f;
  vertices.push_back(v);
  v = -0.5f;
  vertices.push_back(v);
  v = 0.3f;
  vertices.push_back(v);

  return vertices;
}
