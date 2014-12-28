#include "GameLayer.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool GameLayer::init() {
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        //png加入全局cache
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("shoot_background.plist");
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("shoot.plist");
        
        background1 = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
        background1->setAnchorPoint(ccp(0, 0));
        background1->setPosition(ccp(0, 0));
        this->addChild(background1);
        
        background2 = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
        background2->setAnchorPoint(ccp(0, 0));
        background2->setPosition(ccp(0, background2->getContentSize().height - 2));
        this->addChild(background2);
        
        this->planeLayer = PlaneLayer::create();
        addChild(planeLayer);
        
        schedule(schedule_selector(GameLayer::backgrondMove), 0.01f);
        
        bRet = true;

    } while (0);
    
    return bRet;
}

void GameLayer::backgrondMove(float dt) {
    background1->setPositionY(background1->getPositionY() - 2);
    background2->setPositionY(background1->getPositionY() + background1->getContentSize().height - 2);
    if(background2->getPositionY() == 0) {
        background1->setPositionY(0);
    }
}