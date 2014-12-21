//
//  GameScene.h
//  airplane
//
//  Created by PurpleK on 14/12/21.
//
//

#ifndef airplane_GameScene_h
#define airplane_GameScene_h

#include "cocos2d.h"
#include "GameLayer.h"

class GameScene : public cocos2d::CCScene {
    
public:
    GameScene();
    
    ~GameScene();
    
    CREATE_FUNC(GameScene);
    
    virtual bool init();
    
    GameLayer* _gameLayer;
};


#endif