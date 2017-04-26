//
//  Triangle2D.cpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "Triangle2D.hpp"

GLfloat Triangle2D::vertexs[] = {
    0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f
};

GLuint Triangle2D::indexs[] = {
    0, 1, 2
};

Triangle2D::Triangle2D() {
    color = {1.0f, 1.0f, 0.2f, 1.0f};
}

Triangle2D::Triangle2D(Vector4F color) {
    this->color = color;
}

void Triangle2D::setColor(Vector4F color) {
    this->color = color;
}

void Triangle2D::draw() {
    glUniform4f(GLES::colorHandle, color.x, color.y, color.z, color.w);
    
    glVertexAttribPointer(GLES::positionHandle, 3, GL_FLOAT, false, 0, vertexs);
    
    glDrawElements(GL_TRIANGLES, sizeof(indexs) / sizeof(indexs[0]), GL_UNSIGNED_INT, indexs);
}
