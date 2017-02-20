//
//  glCube.cpp
//  CocosEffect
//
//  Created by happyelements on 2017/2/20.
//
//

#include "glCube.h"

glCube::glCube(){}

glCube::~glCube(){}

glCube* glCube::create(){
    auto cube = new (std::nothrow) glCube();
    if (cube)
    {
        cube->autorelease();
        cube->initWithDefault();
        return cube;
    }
    
    CC_SAFE_DELETE(cube);
    return NULL;
}

void glCube::initWithDefault(){
    setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_COLOR));
}

void glCube::onDraw(const Mat4& transform, uint32_t flags){
    auto glProgram = getGLProgram();
    glProgram->use();
    glProgram->setUniformsForBuiltins();
    
//    //draw triangle
//    auto visiableSize = Director::getInstance()->getVisibleSize();
//    // 指定将要绘制的三角形的三个顶点
//    float vertercies[] = { 0,0,     //第一个点的坐标
//        visiableSize.width,0,   //第二个点的坐标
//        visiableSize.width / 2, visiableSize.height};   //第三个点的坐标
//    // 指定每一个顶点的颜色，颜色值是RGBA格式的，取值范围是0-1
//    float color[] = { 0, 1,0, 1,    //第一个点的颜色，绿色
//        1,0,0, 1,  //第二个点的颜色, 红色
//        0, 0, 1, 1};  //第三个点的颜色， 蓝色
//    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
//    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertercies);
//    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, color);
//    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    float* vertexBuffer = NULL;
    float* coordBuffer = NULL;
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex,Position));
    
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex,Color));


        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE,(GLvoid*)0);

}

void glCube::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) {
    m_customCommand.init(_globalZOrder);
    m_customCommand.func = CC_CALLBACK_0(glCube::onDraw, this, transform, flags);
    renderer->addCommand(&m_customCommand);
}
