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
"layout (location=0) in vec3 aPos; \n"
"layout (location = 1) in vec3 aColor; \n"
"layout (location = 2) in vec2 aTexCoord; \n"
"out vec3 ourColor; \n"
"out vec2 TexCoord; \n"
"void main(){ \n"
"gl_Position=vec4(aPos,1.0f); \n"
"ourColor = aColor; \n"
"TexCoord=aTexCoord; \n"
"}";

static const char *FragmentShaderSource="#version 330 core \n"
"out vec4 FragColor; \n"
"in vec3 ourColor; \n"
"in vec2 TexCoord; \n"
"uniform sampler2D texture1; \n"
"uniform sampler2D texture2; \n"
"void main(){ \n"
"FragColor=mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2); \n"
"}";

class TestSquare{
  
public:
    TestSquare();
    
    void draw();
};



#endif /* TestSquare_hpp */
