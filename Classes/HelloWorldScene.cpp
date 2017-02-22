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

//    auto sprite = glCube::create(); //Sprite::create("HelloWorld.png");
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    sprite->runAction(RotateBy::create(1.5,90));
//    this->addChild(sprite, 0);
    
    auto sprite = Sprite::create("HelloWorld.png");
    this->addChild(sprite);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
   // sprite->setScale(3,3);
//    sprite->setGLProgram(GLProgram::createWithFilenames("shaders/fraction.vsh","shaders/fraction.fsh"));
//    sprite->setGLProgram(GLProgram::createWithFilenames("shaders/streamer.vsh","shaders/streamer.fsh"));
    //sprite->setGLProgram(GLProgram::createWithFilenames("shaders/blur.vsh","shaders/blur.fsh"));
	sprite->setGLProgram(GLProgram::createWithFilenames("shaders/bloom.vsh", "shaders/bloom.fsh"));
    return true;
}

