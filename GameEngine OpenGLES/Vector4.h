//
//  Vector4.h
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef Vector4_h
#define Vector4_h

#include <OpenGLES/ES3/gl.h>

typedef struct Vector4 {
    GLint x;
    GLint y;
    GLint z;
    GLint w;
};

typedef struct Vector4F {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
};

#endif /* Vector4_h */
