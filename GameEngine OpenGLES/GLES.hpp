//
//  GLES.hpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef GLES_hpp
#define GLES_hpp

#include <OpenGLES/ES3/gl.h>
#include <string>
#include <stdlib.h>

using namespace std;

class GLES {
private:
    static const string VERTEX_CODE;
    static const string FRAGMENT_CODE;
    
    static GLuint program;

public:
    static GLuint positionHandle; // Handle Position
    static GLuint colorHandle; // Handle Color

    static void makeProgram();
    static GLuint loadShader(GLenum shaderType, const char *pSource);
};

#endif /* GLES_hpp */
