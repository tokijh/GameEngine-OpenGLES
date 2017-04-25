//
//  Triangle2D.hpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef Triangle2D_hpp
#define Triangle2D_hpp

#include "Object.hpp"

class Triangle2D : public Object {
private:
    static GLfloat vertexs[];
public:
    Triangle2D();
    Triangle2D(Vector4F color);
    
    void setColor(Vector4F color);
    
    virtual void draw();
};

#endif /* Triangle2D_hpp */
