#include "glCube.h"
Vertex data[] =
{
    // Front
    { {1, -1, 0}, {1, 0, 0, 1}},
    { {1, 1, 0}, {0, 1, 0, 1}},
    { {-1, 1, 0}, {0, 0, 1, 1}},
    { {-1, -1, 0}, {0, 0, 0, 1}},
    // Back
    { {1, 1, -2}, {1, 0, 0, 1}},
    { {-1, -1, -2}, {0, 1, 0, 1}},
    { {1, -1, -2}, {0, 0, 1, 1}},
    { {-1, 1, -2}, {0, 0, 0, 1}},
    // Left
    { {-1, -1, 0}, {1, 0, 0, 1}},
    { {-1, 1, 0}, {0, 1, 0, 1}},
    { {-1, 1, -2}, {0, 0, 1, 1}},
    { {-1, -1, -2}, {0, 0, 0, 1}},
    // Right
    { {1, -1, -2}, {1, 0, 0, 1}},
    { {1, 1, -2}, {0, 1, 0, 1}},
    { {1, 1, 0}, {0, 0, 1, 1}},
    { {1, -1, 0}, {0, 0, 0, 1}},
    // Top
    { {1, 1, 0}, {1, 0, 0, 1}},
    { {1, 1, -2}, {0, 1, 0, 1}},
    { {-1, 1, -2}, {0, 0, 1, 1}},
    { {-1, 1, 0}, {0, 0, 0, 1}},
    // Bottom
    { {1, -1, -2}, {1, 0, 0, 1}},
    { {1, -1, 0}, {0, 1, 0, 1}},
    { {-1, -1, 0}, {0, 0, 1, 1}},
    { {-1, -1, -2}, {0, 0, 0, 1}}
};
GLubyte indices[] = {
    // Front
    0, 1, 2,
    2, 3, 0,
    // Back
    4, 5, 6,
    4, 5, 7,
    // Left
    8, 9, 10,
    10, 11, 8,
    // Right
    12, 13, 14,
    14, 15, 12,
    // Top
    16, 17, 18,
    18, 19, 16,
    // Bottom
    20, 21, 22,
    22, 23, 20
};


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
    auto program = new GLProgram;
    program->initWithFilenames("shaders/glCube.vsh", "shaders/glCube.fsh");
    program->link();
    program->updateUniforms();
    setGLProgram(program);
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1,&vertexVBO);
    glGenBuffers(1, &indexBuffer);
    auto visiableSize = Director::getInstance()->getVisibleSize();
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        auto p = data[i].Position;
        for (int j = 0; j<3; j++) {
            p[j] = p[j] * visiableSize.width/2;
        }
    }
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
    
    
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices, GL_STATIC_DRAW);
    
    positionLocation = glGetAttribLocation(glProgram->getProgram(), "a_position");
    glEnableVertexAttribArray(positionLocation);
    glVertexAttribPointer(positionLocation,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex,Position));
        
    colorLocation = glGetAttribLocation(glProgram->getProgram(), "a_color");
    glEnableVertexAttribArray(colorLocation);
    glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex,Color));

//    //使用VAO
    glBindVertexArray(vao);
    //渲染
    glDrawElements(GL_TRIANGLES,  36, GL_UNSIGNED_BYTE,0);
    int vertexSize = sizeof(data)/sizeof(data[0]);
     CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1,vertexSize);
    //清空VAO
    glBindVertexArray(0);
//
//    int vertexCount = sizeof(data) / sizeof(data[0]);
//    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1,vertexCount);
}

void glCube::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) {
    m_customCommand.init(_globalZOrder);
    m_customCommand.func = CC_CALLBACK_0(glCube::onDraw, this, transform, flags);
    renderer->addCommand(&m_customCommand);
}
