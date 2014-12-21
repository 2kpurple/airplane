#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class GameLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void backgrondMove(float dt);
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameLayer);
    
private:
    
    cocos2d::CCSprite* background1;
    cocos2d::CCSprite* background2;
};

#endif // __HELLOWORLD_SCENE_H__
