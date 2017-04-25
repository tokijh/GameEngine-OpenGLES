//
//  GameEngineWrapper.mm
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#import "GameEngineWrapper.h"
#import "GameEngine.hpp"

@implementation GameEngineWrapper {
    GameEngine *gameEngine;
}

-(id)init {
    self = [super init];
    gameEngine = &GameEngine::getInstance();
    return self;
}

- (void)dealloc {
    gameEngine->destroy();
}

- (void) onCreated {
    gameEngine->onCreated();
}

- (void) onChanged : (int) width : (int) height {
    gameEngine->onChanged(width, height);
}

- (void) onDraw {
    gameEngine->onDraw();
}

- (void) onTouch : (int) eventsCount : (int **) touchInfo {
    gameEngine->onTouch(eventsCount, touchInfo);
}

- (void) onDestroy {
    gameEngine->onDestroy();
}

@end
