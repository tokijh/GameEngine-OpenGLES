//
//  GameEngine.hpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <stdio.h>
#include <OpenGLES/ES3/gl.h>
#include "GLES.hpp"

class GameEngine {
    private :
    GameEngine();
    
    public :
    static GameEngine &getInstance();
    static void destroy();
    
    void onCreated();
    void onChanged(int width, int height);
    void onDraw();
    void onTouch(int eventsCount, int **touchInfo);
    void onDestroy();
};

#endif /* GameEngine_hpp */
