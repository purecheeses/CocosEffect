#ifndef glCube_hpp
#define glCube_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

typedef struct {
    float Position[3];
    float Color[4];
} Vertex;


class glCube:public Node{
public:
    glCube();
    virtual ~glCube();
public:
    static glCube* create();
    void initWithDefault();
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags) override;
    void onDraw(const Mat4& transform, uint32_t flags);
    //        virtual void update(float dt);
protected:
    CustomCommand m_customCommand;
private:
    GLuint vao;
    GLuint vertexVBO;
    GLuint indexBuffer;
    GLuint positionLocation;
    GLuint colorLocation;
    
};

#endif /* glCube_hpp */
