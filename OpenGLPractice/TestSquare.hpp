//
//  TestSquare.hpp
//  OpenGLPractice
//
//  Created by developer on 2019/8/22.
//  Copyright © 2019 developer. All rights reserved.
//

#ifndef TestSquare_hpp
#define TestSquare_hpp

#include <stdio.h>

#include <iostream>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"



static const char *VertexShaderSource="#version 330 core \n"
"layout(location=0) in vec4 aPos; \n"
"void main(){ \n"
"gl_Position=aPos; \n"
"}";

static const char *FragmentShaderSource="#version 330 core \n"
"out vec4 FragColor; \n"
"void main(){ \n"
"FragColor=vec4(1.0f,0.0f,0.0f,0.0f); \n"
"}";

class TestSquare{
  
public:
    TestSquare();
    
    void draw();
};



#endif /* TestSquare_hpp */
