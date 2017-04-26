//
//  Rectangle2D.hpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 26..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef Rectangle2D_hpp
#define Rectangle2D_hpp

#include "Object.hpp"

class Rectangle2D : public Object {
private:
    static GLfloat vertexs[];
public:
    Rectangle2D();
    Rectangle2D(Vector4F color);
    
    void setColor(Vector4F color);
    
    virtual void draw();
};

#endif /* Rectangle2D_hpp */
