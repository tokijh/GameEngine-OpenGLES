//
//  Vector3.h
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef Vector3_h
#define Vector3_h

#include <OpenGLES/ES3/gl.h>

typedef struct Vector3 {
    GLint x;
    GLint y;
    GLint z;
};

typedef struct Vector3F {
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

#endif /* Vector3_h */
