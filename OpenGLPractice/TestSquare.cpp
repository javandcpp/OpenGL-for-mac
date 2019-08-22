//
//  TestSquare.cpp
//  OpenGLPractice
//
//  Created by developer on 2019/8/22.
//  Copyright © 2019 developer. All rights reserved.
//

#include "TestSquare.hpp"

TestSquare::TestSquare(){
    
}

void TestSquare::draw(){
    
    using namespace std;
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow *window=glfwCreateWindow(400, 400, "OpenGL", NULL, NULL);
    if (!window) {
        cout<<"glfwCreateWindow failed"<<endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
     
        cout<<"gladLoadGLLoader failed!"<<endl;
        glfwTerminate();
        return;
    }
    
    GLuint vertexShader;
    vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&VertexShaderSource,NULL);
    glCompileShader(vertexShader);
    
    int success;
    char logInfo[512];
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if (!success) {
        glGetShaderInfoLog(vertexShader,512,0,logInfo);
        cout<<"glCompile vertex shader error:"<<logInfo<<endl;
        return;
    }
    
    GLuint fragmentShader;
    fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&FragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader,512,0,logInfo);
        cout<<"glcompile fragment shader error:"<<logInfo<<endl;
        return;
    }
    
    GLuint program;
    program=glCreateProgram();
    glAttachShader(program,vertexShader);
    glAttachShader(program,fragmentShader);
    glLinkProgram(program);
    
    glGetProgramiv(program,GL_COMPILE_STATUS,&success);
    if (!success) {
        glGetProgramInfoLog(program,512,0,logInfo);
        cout<<"glLinkProgram error:"<<logInfo<<endl;
        return;
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
   
    
    
   
    float vertex[]={
        -0.5f,-0.5f,-0.5f,
        0.5f,-0.5f,-0.5f,
        0.5f,0.5f,-0.5f,
        -0.5f,0.5f,-0.5f
    };
    
    unsigned int index[]={
        0,1,2,
        0,3,2
        
    };
    
    
    unsigned int VAO,VBO,EBO;
    
   
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
  
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertex),vertex,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(index),index,GL_STATIC_DRAW);
    
 
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    
    glViewport(0,0,400,400);
    
    while (!glfwWindowShouldClose(window)) {
        
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        
        glUseProgram(program);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
//        glBindVertexArray(0);
        
        if(glfwGetKey(window, GLFW_KEY_ESCAPE)==GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    
    
    
    
    glfwTerminate();
    return;
    
}
