#include <glew.h>
#include <glfw3.h>

void key_callback_square(GLFWwindow *window, int key, int scanmode, int action, int mode){
    if(key == GLFW_KEY_ESCAPE && action ==GLFW_PRESS){
        glfwWindowShouldClose(GL_TRUE);
    }
}

int main4(void){
    if(!glfwInit()){
        return -1;
    }
     GLFWwindow *window = glfwCreateWindow(600,600,"hello square",NULL,NULL);
     if(!window){
         glfwTerminate();
     }
     glfwMakeContextCurrent(window);
     glfwSetKeyCallback(window,key_callback_square);
    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex3f(-0.5, -0.5, 0.0);

        glColor3f(0,1,0);
        glVertex3f(0.5, -0.5, 0.0);

        glColor3f(0,0,1);
        glVertex3f(0.5, 0.5, 0.0);

        glColor3f(1,0,0);
        glVertex3f(-0.5, 0.5, 0.0);
        //结束一个画图步骤
        glEnd();

        /******交换缓冲区，更新window上的内容******/
        glfwSwapBuffers(window);

    }
    glfwTerminate();
}
