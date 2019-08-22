//
//  Square.hpp
//  OpenGLPractice
//
//  Created by developer on 2019/8/22.
//  Copyright © 2019 developer. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include <stdio.h>

#include <iostream>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#define GETSQUARESHADER(x) #x

static const char *squareVertexShaderSource="#version 330 core \n"
"layout(location=0) in vec4 position; \n"
"void main(){ \n"
"gl_Position = position; \n"
"}";


static const char *squareFragmentShaderSource="#version 330 core \n"
"out vec4 FragColor; \n"
"void main(){ \n"
"FragColor=vec4(1.0f,0.0f,0.0f,0.0f); \n"
"}\n";



class Square{
  
    
public:
    Square();
    void draw();
    void processInput(GLFWwindow *window);
};

#endif /* Square_hpp */
