//
//  main.cpp
//  OpenGLPractice
//
//  Created by developer on 2018/10/16.
//  Copyright © 2018 developer. All rights reserved.
//

#include "Triangle.h"
#include "Square.hpp"
#include "TestSquare.hpp"

int main(int argc, char **argv){
    using namespace std;
//    Triangle tr;
//    tr.draw();
    
//    Square square;
//    square.draw();
    TestSquare testSqr;
    testSqr.draw();
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    //
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


