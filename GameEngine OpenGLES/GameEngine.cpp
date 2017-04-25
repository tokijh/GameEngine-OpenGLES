//
//  GameEngine.cpp
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "GameEngine.hpp"

GameEngine::GameEngine() {
    
}

GameEngine& GameEngine::getInstance() {
    static GameEngine *instance = NULL;
    
    if (instance == NULL) {
        instance = new GameEngine();
    }
    
    return *instance;
}

void GameEngine::destroy() {
    GameEngine *gameEngine = &getInstance();
    
    if (gameEngine != NULL) {
        delete gameEngine;
    }
}

void GameEngine::onCreated() {
    printf("onCreated\n");
    
    GLES::makeProgram();
    
    glEnableVertexAttribArray(GLES::positionHandle);
}

void GameEngine::onChanged(int width, int height) {
    printf("onChanged width : %d height : %d\n", width, height);
    
    glViewport(0, 0, width, height);
}

void GameEngine::onDraw() {
//    printf("onDraw\n");
    
    // To change red color
    static float red_color = 0.0f;
    
    // Init Triangle2D object
    static Triangle2D triangle2d = Triangle2D();
    
    // Increase red color
    red_color = red_color + 0.01f;
    if (red_color > 1.0f) {
        red_color = 0.0f;
    }
    
    // Clear background by color
    glClearColor(red_color, 1.0f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Change red color on stap 
    triangle2d.setColor({1.0f - red_color, 1.0f, 0.2f, 1.0f});
    triangle2d.draw();
}

void GameEngine::onTouch(int eventsCount, int **touchInfo) {
    printf("onTouch\n");
}

void GameEngine::onDestroy() {
    printf("onDestroy\n");
}

