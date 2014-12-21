//
//  GameScene.cpp
//  airplane
//
//  Created by PurpleK Fung on 14/12/21.
//
//

#include "GameScene.h"

USING_NS_CC;

GameScene::GameScene(){
    _gameLayer = NULL;
}

GameScene::~GameScene(){
    
}

bool GameScene::init(){
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCScene::init());
        _gameLayer = GameLayer::create();
        CC_BREAK_IF(!_gameLayer);
        this->addChild(_gameLayer);
        bRet = true;
    } while (0);
    
    return bRet;
}




