//
//  Light.hpp
//  OpenGLPractice
//
//  Created by developer on 2019/8/28.
//  Copyright © 2019 developer. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#include <stdio.h>

#include <stdio.h>

#include <iostream>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"





static const char *LightVertexShaderSource="#version 330 core \n"
"layout (location=0) in vec3 aPos; \n"
"layout (location = 1) in vec3 aColor; \n"
"layout (location = 2) in vec2 aTexCoord; \n"
"out vec3 ourColor; \n"
"out vec2 TexCoord; \n"
"uniform mat4 transform; \n"
"uniform mat4 model; \n"
"uniform mat4 view; \n"
"uniform mat4 projection; \n"
"void main(){ \n"
"gl_Position=projection * view * model * vec4(aPos,1.0f); \n"
"ourColor = aColor; \n"
"TexCoord=aTexCoord; \n"
"}";

static const char *LightFragmentShaderSource="#version 330 core \n"
"out vec4 FragColor; \n"
"in vec3 ourColor; \n"
"in vec2 TexCoord; \n"
"uniform sampler2D texture1; \n"
"uniform sampler2D texture2; \n"
"void main(){ \n"
"FragColor=mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2); \n"
"}";

class Light{
    
public:
    Light();
    
    void draw();
};



#endif /* Light_hpp */
