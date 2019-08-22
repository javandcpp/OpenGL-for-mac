//
//  Triangle.hpp
//  OpenGLPractice
//
//  Created by developer on 2018/10/16.
//  Copyright © 2018 developer. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp
#include <iostream>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#define GETSHADER(x) #x

static const char *vertexShaderSource="#version 330 core \n"
"layout (location = 0) in vec4 position;\n"
"uniform mat4 transform;\n"
"out vec4 vertexColor;\n"  //输出
"void main(){\n"
"gl_Position=position;\n"
"vertexColor=vec4(1.0f, 0.5f, 0.2f, 0.0f);\n"
"}\0";


static const char *fragShaderSource="#version 330 core\n"
"out vec4 FragColor;\n"
"in vec4 vertexColor;\n"   //输入
"void main()\n"
"{\n"
"   FragColor = vertexColor;\n"
"}\n\0";


class Triangle{
public:
    Triangle();
    virtual ~Triangle();
    void draw();
    
};

#endif /* Triangle_hpp */
