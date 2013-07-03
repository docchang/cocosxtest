//
//  cocosxtest12AppDelegate.cpp
//  cocosxtest12
//
//  Created by Dominic Chang on 7/2/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

#include "common_function.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

//    // create a scene. it's an autorelease object
//    CCScene *pScene = HelloWorld::scene();
//
//    // run
//    pDirector->runWithScene(pScene);
    
    
    // Load the main menu scene from the ccbi-file
    map<string, CCNodeLoader*> loader_map;
    loader_map.insert(make_pair("HelloWorld", HelloWorldLoader::loader()));
    CCScene* mainScene = (CCScene*)loadCCBFile("HelloWorld.ccbi", loader_map);
    if (mainScene) {
        // Then add the scene to the stack. The director will run it when it automatically when the view is displayed.
        pDirector->runWithScene(mainScene);
    }

    

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
