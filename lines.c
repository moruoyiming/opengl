#include <glew.h>
#include <glfw3.h>

void key_callback_lines(GLFWwindow *window, int key, int scanmode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwWindowShouldClose(GL_TRUE);
    }
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main(void) {
    if (!glfwInit())
        return -1;
    GLFWwindow *window = glfwCreateWindow(640, 640, "hello lines", NULL, NULL);
    if (!window) {
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback_lines);
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glfwPollEvents();
        glClearColor(0.2, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);

        glColor3f(1, 0, 0);
        glVertex3f(2, 0, 0);

        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);

        glColor3f(1, 0, 0);
        glVertex3f(-2, 0, 0);

        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);

        glColor3f(1, 0, 0);
        glVertex3f(0, 2, 0);

        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);

        glColor3f(1, 0, 0);
        glVertex3f(0, -2, 0);

        //结束一个画图步骤
        glEnd();
        /******交换缓冲区，更新window上的内容******/
        glfwSwapBuffers(window);

    }
    glfwTerminate();

}