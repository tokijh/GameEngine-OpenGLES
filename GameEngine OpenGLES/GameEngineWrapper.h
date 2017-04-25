//
//  GameEngineWrapper.h
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GameEngineWrapper : NSObject
- (void) onCreated;
- (void) onChanged:(int) width : (int) height;
- (void) onDraw;
- (void) onTouch:(int) eventsCount : (int **) touchInfo;
- (void) onDestroy;
@end
