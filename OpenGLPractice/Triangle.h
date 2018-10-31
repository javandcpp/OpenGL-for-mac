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
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 transform;\n"
"void main(){\n"
"gl_Position=vec4(aPos,1.0);\n"
"}\0";


static const char *fragShaderSource="#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


class Triangle{
public:
    Triangle();
    virtual ~Triangle();
    void draw();
    
};

#endif /* Triangle_hpp */
