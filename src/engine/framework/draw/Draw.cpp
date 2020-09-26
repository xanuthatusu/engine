#include "Draw.h"

void Draw::AddShape(Shape* shape) {
  shapes.push_back(shape);
}

void Draw::UpdateScreen() {
  static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
  static const float red[] = { 1.0f, 0.0f, 0.0f, 0.0f };

  glClearBufferfv(GL_COLOR, 0, black);

  glBindVertexArray(VAOs[Triangles]);
  glDrawArrays(GL_TRIANGLES, 0, NumVertices);

  glFlush();
}

Draw::Draw() {
  glGenVertexArrays(NumVAOs, VAOs);
  glBindVertexArray(VAOs[Triangles]);

  GLfloat vertices[NumVertices][2] = {
    { -0.90f, -0.90f }, {  0.85f, -0.90f }, { -0.90f,  0.85f },
    {  0.90f, -0.85f }, {  0.90f,  0.90f }, { -0.85f,  0.90f },
  };

  glGenBuffers(NumBuffers, Buffers);
  glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vPosition);
}
