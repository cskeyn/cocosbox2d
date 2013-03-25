/*
 * SysMenu.cpp
 *
 *  Created on: 2013-2-28
 *      Author: cske
 */

#include "SysMenu.h"
#include "VisibleRect.h"
#include "TennisTable.h"

using namespace cocos2d;


SysMenu::SysMenu() {
	// TODO Auto-generated constructor stub

}

SysMenu::~SysMenu() {
	// TODO Auto-generated destructor stub
}

CCScene* SysMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    SysMenu *layer = SysMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SysMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(SysMenu::menuCallback) );
    pCloseItem->setTag(0);
    pCloseItem->setPosition( ccp(size.width-20, 20) );

    CCLabelTTF* playLabel = CCLabelTTF::create("PLAY", "Arial", 64);
    CCMenuItemLabel* pPlayItem = CCMenuItemLabel::create(playLabel, this, menu_selector(SysMenu::menuCallback));
    pPlayItem->setTag(1);
    pPlayItem->setPosition(ccp( VisibleRect::center().x , VisibleRect::center().y+200 ));

    CCLabelTTF* optionLabel = CCLabelTTF::create("OPTION", "Arial", 64);
    CCMenuItemLabel* pOptionItem = CCMenuItemLabel::create(optionLabel, this, menu_selector(SysMenu::menuCallback));
    pOptionItem->setTag(2);
    pOptionItem->setPosition(ccp( VisibleRect::center().x , VisibleRect::center().y+100 ));

    CCLabelTTF* setLabel = CCLabelTTF::create("SET", "Arial", 64);
    CCMenuItemLabel* pSetItem = CCMenuItemLabel::create(setLabel, this, menu_selector(SysMenu::menuCallback));
    pSetItem->setTag(3);
    pSetItem->setPosition(ccp( VisibleRect::center().x , VisibleRect::center().y ));

    CCLabelTTF* quitLabel = CCLabelTTF::create("QUIT", "Arial", 64);
    CCMenuItemLabel* pQuitItem = CCMenuItemLabel::create(quitLabel, this, menu_selector(SysMenu::menuCallback));
    pQuitItem->setTag(4);
    pQuitItem->setPosition(ccp( VisibleRect::center().x , VisibleRect::center().y-100 ));

    CCMenu* pMenu = CCMenu::create(pCloseItem, pPlayItem, pOptionItem, pSetItem, pQuitItem,  NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("bg.png");

    pSprite->setContentSize(size);

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    return true;
}

void SysMenu::menuCallback(CCObject* pSender)
{
	if(((CCNode*)pSender)->getTag() == 0){
		CCDirector::sharedDirector()->end();
	}else{
		CCScene * pScene = CCScene::create();
		CCLayer * pLayer = TennisTable::create();
		pScene->addChild(pLayer);
		CCDirector::sharedDirector()->replaceScene(pScene);
	}


}

