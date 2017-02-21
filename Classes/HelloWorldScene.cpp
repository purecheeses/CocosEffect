#include "HelloWorldScene.h"
#include "glCube.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = glCube::create(); //Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->runAction(RotateBy::create(1.5,90));
    //sprite->setPosition(Vec2(0,0));
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


