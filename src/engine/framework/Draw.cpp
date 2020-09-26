#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <engine/framework/Draw.h>

void Draw::AddShape(Shape* shape) {
  shapes.push_back(shape);
}

void Draw::UpdateScreen() {
  static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  static const float red[] = { 1.0f, 0.0f, 0.0f, 0.0f };

  glClearBufferfv(GL_COLOR, 0, black);

  glBindVertexArray(VAOs[Triangles]);
  glDrawArrays(GL_TRIANGLES, 0, 3);

  glFlush();
}

Draw::Draw() {
  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray(VAOs[Triangles]);

  std::vector<GLfloat> vertices = getVertices();

  glGenBuffers(NumBuffers, Buffers);
  glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), 0);
  glEnableVertexAttribArray(vPosition);
}

std::vector<GLfloat> Draw::getVertices() {
  std::vector<GLfloat> vertices;

  for (int i = 0; i < 3; i++) {
    GLfloat v = 0.3f * (i+1);
    vertices.push_back(v);
    vertices.push_back(v);
  }

  return vertices;
}
