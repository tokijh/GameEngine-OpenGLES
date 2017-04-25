//
//  GLES.cpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "GLES.hpp"

const string GLES::VERTEX_CODE =
    "attribute vec4 a_Position;\
    void main() { \
        gl_Position = a_Position;\
    }";
const string GLES::FRAGMENT_CODE =
    "precision mediump float;\
    uniform vec4 u_Color;\
    void main() {\
        gl_FragColor=u_Color;\
    }";
GLuint GLES::program;
GLuint GLES::positionHandle;
GLuint GLES::colorHandle;

void GLES::makeProgram() {
    // Create Shader Object
    int vertexShader = loadShader(GL_VERTEX_SHADER, VERTEX_CODE.c_str());
    int fragmentShader = loadShader(GL_FRAGMENT_SHADER, FRAGMENT_CODE.c_str());
    
    // Create Shader Object
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    
    // Get Handle
    positionHandle = glGetAttribLocation(program, "a_Position");
    colorHandle = glGetUniformLocation(program, "u_Color");
    
    // Use created program
    glUseProgram(program);
}

GLuint GLES::loadShader(GLenum shaderType, const char *pSource) {
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char *buf = (char *) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    printf("Could not compile shader %d:\n%s\n",
                         shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}
