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
    
    // Vertexs of a Triangle
    static float triangle_vertexs[] = {
        0.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f
    };
    
    // Increase red color
    red_color = red_color + 0.01f;
    if (red_color > 1.0f) {
        red_color = 0.0f;
    }
    
    // Clear background by color
    glClearColor(1.0f, red_color, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Reverse color with background
    glUniform4f(GLES::colorHandle, 1.0f, 1.0f - red_color, 0.2f, 1.0f);
    
    glVertexAttribPointer(GLES::positionHandle, 3, GL_FLOAT, false, 0, triangle_vertexs);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GameEngine::onTouch(int eventsCount, int **touchInfo) {
    printf("onTouch\n");
}

void GameEngine::onDestroy() {
    printf("onDestroy\n");
}

