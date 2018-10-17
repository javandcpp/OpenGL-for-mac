//
//  main.cpp
//  OpenGLPractice
//
//  Created by developer on 2018/10/16.
//  Copyright © 2018 developer. All rights reserved.
//

#include "Triangle.h"

int main(int argc, char **argv){
    using namespace std;
//    Triangle tr;
//    tr.draw();
    
    glm::mat4 trans;
    for (int i = 0; i < 4; ++i)
    {
        cout << trans[i].x << " " << trans[i].y << " " << trans[i].z << " " << trans[i].w << endl;
    }
    trans = glm::rotate(trans, 30.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    cout << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << trans[i].x << " " << trans[i].y << " " << trans[i].z << " " << trans[i].w << endl;
    }
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


