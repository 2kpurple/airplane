//
//  PlaneLayer.cpp
//  airplane
//
//  Created by PurpleK Fung on 14/12/22.
//
//

#include "PlaneLayer.h"
USING_NS_CC;

PlaneLayer* PlaneLayer::sharedPlane = NULL;

int AIRPLANE = 1;

PlaneLayer::PlaneLayer(){
    
}

PlaneLayer::~PlaneLayer(){
    
}

PlaneLayer* PlaneLayer::create(){
	PlaneLayer *pRet = new PlaneLayer();
	if(pRet && pRet->init()){
		pRet->autorelease();
		sharedPlane=pRet;
		return pRet;
	} else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool PlaneLayer::init(){
    bool bRet = false;
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        CCSprite* plane = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero1.png"));
        plane->setPosition(ccp(winSize.width/2,plane->getContentSize().height/2));//飞机放置在底部中央
        this->addChild(plane,0,AIRPLANE);//添加精灵，AIRPLANE是tag
        
        CCBlink* blink = CCBlink::create(1, 3);
        CCAnimation* animation = CCAnimation::create();
        animation->setDelayPerUnit(0.1f);
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero1.png"));
        animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero2.png"));
        CCAnimate* animate=CCAnimate::create(animation);//帧动画
        
        plane->runAction(blink);//执行闪烁动画
        plane->runAction(CCRepeatForever::create(animate));// 执行帧动画
        
        bRet=true;
    } while (0);
    
    return bRet;
}