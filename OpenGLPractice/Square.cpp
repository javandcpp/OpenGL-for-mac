//
//  Square.cpp
//  OpenGLPractice
//
//  Created by developer on 2019/8/22.
//  Copyright © 2019 developer. All rights reserved.
//

#include "Square.hpp"
using namespace std;
Square::Square(){
    
    
}

void Square::processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Square::draw(){
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow *window=glfwCreateWindow(400, 400, "OpenGL", NULL, NULL);
    if(!window){
        cout<<"Failed to create window!"<<endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout<<"Filed to initialize glad"<<endl;
        glfwTerminate();
        return;
    }
    
    
    /***********创建、编译、链接 着色器****************/
    
    //创建、编译顶点着色器
    GLuint vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&squareVertexShaderSource,NULL);
    glCompileShader(vertexShader);
    int success;
    char logInfo[512];
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if (!success) {
        glGetShaderInfoLog(vertexShader,512,NULL,logInfo);
        cout<<"compile vertex shader error:"<<logInfo<<endl;
        return;
    }
    
    
    GLuint fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&squareFragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader,512,NULL,logInfo);
        cout<<"compile fragment shader error:"<<logInfo<<endl;
        return;
    }
    
  
    
    GLuint program=glCreateProgram();
    glAttachShader(program,vertexShader);
    glAttachShader(program,fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program,GL_COMPILE_STATUS,&success);
    if (!success) {
        glGetProgramInfoLog(program,512,NULL,logInfo);
        cout<<"link program error:"<<logInfo<<endl;
    }
    
    
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    float vertexArray[]={
        -0.5f,-0.5f,-0.5f,
        0.5f,-0.5f,-0.5f,
        0.5f,0.5f,-0.5f,
        -0.5f,0.5f,-0.5f
    };
    
    
    unsigned int indices[]={
        0,1,2,
        0,3,2
    };
    
    unsigned int VAO,VBO,EBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexArray),vertexArray,GL_STATIC_DRAW);
    
    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
   
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    
   
    
    /***********创建、编译、链接 着色器****************/
    glViewport(0,0,400,400);
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    while(!glfwWindowShouldClose(window)){
        
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
      
      
        glUseProgram(program);
        glBindVertexArray(VAO);
        
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        glBindVertexArray(0);
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//      glDrawArrays(GL_TRIANGLES,0,6);
        
        
        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return;
    
}
