#ifndef glCube_hpp
#define glCube_hpp

#include <stdio.h>

USING_NS_CC;

typedef struct {
    float Position[3];
    float Color[4];
} Vertex;

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
};

#endif /* glCube_hpp */
