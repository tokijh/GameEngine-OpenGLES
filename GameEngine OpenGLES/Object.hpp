//
//  Object.hpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <OpenGLES/ES3/gl.h>
#include "Vector.h"
#include "GLES.hpp"

class Object {
public:
    Vector4F color;
    virtual void draw() = 0;
};

#endif /* Object_hpp */
