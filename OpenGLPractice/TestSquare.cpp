//
//  TestSquare.cpp
//  OpenGLPractice
//
//  Created by developer on 2019/8/22.
//  Copyright © 2019 developer. All rights reserved.
//

#include "TestSquare.hpp"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


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
    
   
    
    
    float vertices[] = {
        // 位置              // 颜色            //纹理坐标
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  3.0f,0.0f,
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,0.0f,
        0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   3.0f,3.0f,
        -0.5f,0.5f,0.0f,    1.0f,1.0f,1.0f,    0.0f,3.0f
    };

    unsigned int index[]={
        0,1,2,
        1,3,2

    };

    
    
   
    
    unsigned int VAO,VBO,EBO;
    
   
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
  
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(index),index,GL_STATIC_DRAW);
    //顶点
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    //颜色
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    //纹理坐标顶点数据
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    //加载、创建纹理
    //nrChannels表示通道数，R/G/B/A，一共4个通道，有些图片只有3个，A即为alpha
    int width,height,nrChannels;
    
   //纹理1
    unsigned int texture1;
    //生成纹理
    glGenTextures(1, &texture1);
    //绑定纹理
    glBindTexture(GL_TEXTURE_2D, texture1);
    
  
    //生成纹理
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    

    
    stbi_set_flip_vertically_on_load(true); //解决图像翻转问题，不需要像SOIL库中片段着色器的position设置为-y
    unsigned char *data =stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    printf("stbi_load   width:%d  height:%d \n",width,height);
    
    if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
        
    }else{
        cout<<"Failed load texture1"<<endl;
    }
    
    stbi_image_free(data);
 
    //纹理2
    unsigned int texture2;
    //生成纹理
    glGenTextures(1, &texture2);
    //绑定纹理
    glBindTexture(GL_TEXTURE_2D, texture2);
    
    
    //生成纹理
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    //加载、创建纹理
    
    data =stbi_load("awesomeface.png", &width, &height, &nrChannels,0);
    printf("stbi_load   width:%d  height:%d \n",width,height);
    
    if (data) {
         if(nrChannels==3)//rgb 适用于jpg图像
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);//png
         else if(nrChannels==4)//rgba 适用于png图像
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);//png
       
        glGenerateMipmap(GL_TEXTURE_2D);
        
    }else{
        cout<<"Failed load texture2"<<endl;
    }
    
    stbi_image_free(data);
   
    
    
   
    
//    glViewport(0,0,400,400);
    
    glUseProgram(program);
    glUniform1i(glGetUniformLocation(program, "texture1"), 0);
    glUniform1i(glGetUniformLocation(program, "texture2"),1);
    
    while (!glfwWindowShouldClose(window)) {
        
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
     
      
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        
        glUseProgram(program);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
        glBindVertexArray(0);
        
        if(glfwGetKey(window, GLFW_KEY_ESCAPE)==GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    
    
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&EBO);
    
    
    
    glfwTerminate();
    return;
    
}
