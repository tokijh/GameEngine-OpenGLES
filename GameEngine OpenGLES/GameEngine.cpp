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
}

void GameEngine::onChanged(int width, int height) {
    printf("onChanged width : %d height : %d\n", width, height);
}

void GameEngine::onDraw() {
//    printf("onDraw\n");
    
    static float a = 0.0f;
    
    glClearColor(1.0f, a, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    a = a + 0.01f;
    if (a > 1.0f) {
        a = 0.0f;
    }
}

void GameEngine::onTouch(int eventsCount, int **touchInfo) {
    printf("onTouch\n");
}

void GameEngine::onDestroy() {
    printf("onDestroy\n");
}

