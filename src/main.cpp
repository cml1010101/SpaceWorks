#include <cstdio>
#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <boost/log/trivial.hpp>
GLFWwindow* initWindow(int width, int height, const char* title)
{
    if (!glfwInit())
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to initialize GLFW";
        throw std::runtime_error("Failed to initialize GLFW");
    }
    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window)
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to create window";
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }
    glfwMakeContextCurrent(window);
    return window;
}
int main()
{
    GLFWwindow* window = initWindow(800, 600, "Hello World");
    if (glewInit() != GLEW_OK)
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to initialize GLEW";
        throw std::runtime_error("Failed to initialize GLEW");
    }
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}