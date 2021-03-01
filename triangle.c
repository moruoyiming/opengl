#include <glew.h>
#include <glfw3.h>
void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window,GL_TRUE);
}

int main3(){
    if(!glfwInit())
        return -1;
    GLFWwindow *window = glfwCreateWindow(640,640,"hell triangle",NULL,NULL);
    if(!window){
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window,key_callback2);
    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glClearColor(0.2, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex3f(0,1,1);

        glColor3f(0,1,0);
        glVertex3f(-1, -1, 0);

        glColor3f(0, 0, 1); //Blue
        glVertex3f(1, -1, 0);
        //结束一个画图步骤
        glEnd();

        /******交换缓冲区，更新window上的内容******/
        glfwSwapBuffers(window);

    }
    glfwTerminate();
}
