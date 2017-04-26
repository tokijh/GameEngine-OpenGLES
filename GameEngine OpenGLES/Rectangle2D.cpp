//
//  Rectangle2D.cpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 26..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "Rectangle2D.hpp"

GLfloat Rectangle2D::vertexs[] = {
    0.5f, 0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f
};

GLuint Rectangle2D::indexs[] = {
    0, 1, 2, 3, 0
};

Rectangle2D::Rectangle2D() {
    color = {1.0f, 1.0f, 0.2f, 1.0f};
}

Rectangle2D::Rectangle2D(Vector4F color) {
    this->color = color;
}

void Rectangle2D::setColor(Vector4F color) {
    this->color = color;
}

void Rectangle2D::draw() {
    glUniform4f(GLES::colorHandle, color.x, color.y, color.z, color.w);
    
    glVertexAttribPointer(GLES::positionHandle, 3, GL_FLOAT, false, 0, vertexs);
    
    glDrawElements(GL_TRIANGLE_STRIP, sizeof(indexs) / sizeof(indexs[0]), GL_UNSIGNED_INT, indexs);
}
