//
//  PlaneLayer.h
//  airplane
//
//  Created by PurpleK Fung on 14/12/22.
//
//

#ifndef __airplane__PlaneLayer__
#define __airplane__PlaneLayer__

#include "cocos2d.h"

class PlaneLayer : public cocos2d::CCLayer{
public:
    PlaneLayer();
    
    ~PlaneLayer();
    
    static PlaneLayer* create();
    
    virtual bool init();
    
    static PlaneLayer* sharedPlane;
};

#endif /* defined(__airplane__PlaneLayer__) */
