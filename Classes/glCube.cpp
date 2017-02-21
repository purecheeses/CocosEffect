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

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

// One color for each vertex. They were generated randomly.
static const GLfloat g_color_buffer_data[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
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
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &colorBuffer);
}
void glCube::onDraw(const Mat4& transform, uint32_t flags){

    Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    Director::getInstance()->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    Director::getInstance()->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    
    Mat4 modelViewMatrix;
    Mat4::createLookAt(Vec3(4,3,3), Vec3(0,0,0), Vec3(0,-1,0), &modelViewMatrix);
//    modelViewMatrix.translate(0, 0,0 );
//    
    static float rotation = 20;
    modelViewMatrix.rotate(Vec3(0,1,0),CC_DEGREES_TO_RADIANS(rotation));
//    
    Mat4 projectionMatrix;
   Mat4::createPerspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f, &projectionMatrix);
    //Mat4::createOrthographic(10,10,1,100,&projectionMatrix);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, projectionMatrix);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, modelViewMatrix);
    auto glProgram = getGLProgram();
    glProgram->use();
    glProgram->setUniformsForBuiltins();
//    //draw triangle
//    auto visiableSize = Director::getInstance()->getVisibleSize();
//    // 指定将要绘制的三角形的三个顶点
//    float vertercies[] = { 0,0,     //第一个点的坐标
//        1,0,   //第二个点的坐标
//        0, 1};   //第三个点的坐标
//    // 指定每一个顶点的颜色，颜色值是RGBA格式的，取值范围是0-1
//    float color[] = { 0, 1,0, 1,    //第一个点的颜色，绿色
//        1,0,0, 1,  //第二个点的颜色, 红色
//        0, 0, 1, 1};  //第三个点的颜色， 蓝色
//    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
//    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertercies);
//    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, color);
//    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    
    
    GL::bindVAO(vao);
    positionLocation = glGetAttribLocation(glProgram->getProgram(), "a_position");
    colorLocation = glGetAttribLocation(glProgram->getProgram(), "a_color");
    
    
    //////不使用vbo索引的立方体
//    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
//    glEnableVertexAttribArray(positionLocation);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//    glVertexAttribPointer(
//                          positionLocation, // The attribute we want to configure
//                          3,                           // size
//                          GL_FLOAT,                    // type
//                          GL_FALSE,                    // normalized?
//                          0,                           // stride
//                          (void*)0                     // array buffer offset
//                          );
//    
//    glEnableVertexAttribArray(colorLocation);
//    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
//    glVertexAttribPointer(
//                          colorLocation,               // The attribute we want to configure
//                          3,                           // size
//                          GL_FLOAT,                    // type
//                          GL_FALSE,                    // normalized?
//                          0,                           // stride
//                          (void*)0                     // array buffer offset
//                          );
//    
//    glEnable(GL_DEPTH_TEST);
//    glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles
//    glDisable(GL_DEPTH_TEST);
    
    ///////使用vbo索引的立方体
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(positionLocation);
    glVertexAttribPointer(positionLocation,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex,Position));
        

    glEnableVertexAttribArray(colorLocation);
    glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex,Color));


    glEnable(GL_DEPTH_TEST);
    glDrawElements(GL_TRIANGLE_STRIP,  sizeof(indices)/sizeof(indices[0]), GL_UNSIGNED_BYTE,0);
    glDisable(GL_DEPTH_TEST);
//    glDisableVertexAttribArray(positionLocation);
//    glDisableVertexAttribArray(colorLocation);
//    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1,vertexSize);
    CHECK_GL_ERROR_DEBUG();
    //清空VAO
    glBindVertexArray(0);

////
////    int vertexCount = sizeof(data) / sizeof(data[0]);
////    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1,vertexCount);
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

}

void glCube::setCamera(){
    Mat4 projectionMatrix;
    Mat4::createPerspective(60, 480/320, 1.0, 42, &projectionMatrix);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, projectionMatrix);
    
    Mat4 modelViewMatrix;
    Mat4::createLookAt(Vec3(0,0,1), Vec3(0,0,0), Vec3(0,1,0), &modelViewMatrix);
    modelViewMatrix.translate(0, 0, -5);
    
    static float rotation = 0;
    modelViewMatrix.rotate(Vec3(1,1,1),CC_DEGREES_TO_RADIANS(rotation));
    rotation++;
    if (rotation < 360) {
        rotation = 0;
    }
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, modelViewMatrix);
}

void glCube::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) {
    m_customCommand.init(_globalZOrder);
    m_customCommand.func = CC_CALLBACK_0(glCube::onDraw, this, transform, flags);
    renderer->addCommand(&m_customCommand);
}
