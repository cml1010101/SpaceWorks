#include <SpaceWorks/graphics/Shader.hpp>
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <boost/log/trivial.hpp>
namespace graphics
{
    Shader::Shader(std::filesystem::path vertexShaderPath, std::filesystem::path fragmentShaderPath)
    {
        std::ifstream vertexShaderFile(vertexShaderPath);
        std::ifstream fragmentShaderFile(fragmentShaderPath);
        if (!vertexShaderFile.is_open())
        {
            BOOST_LOG_TRIVIAL(error) << "Failed to open vertex shader file";
            throw std::runtime_error("Failed to open vertex shader file");
        }
        if (!fragmentShaderFile.is_open())
        {
            BOOST_LOG_TRIVIAL(error) << "Failed to open fragment shader file";
            throw std::runtime_error("Failed to open fragment shader file");
        }
        std::stringstream vertexShaderStream, fragmentShaderStream;
        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();
        std::string vertexShaderSource = vertexShaderStream.str();
        std::string fragmentShaderSource = fragmentShaderStream.str();
        const char* vertexShaderSourceCStr = vertexShaderSource.c_str();
        const char* fragmentShaderSourceCStr = fragmentShaderSource.c_str();
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSourceCStr, nullptr);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
            BOOST_LOG_TRIVIAL(error) << "Failed to compile vertex shader: " << infoLog;
            throw std::runtime_error("Failed to compile vertex shader");
        }
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSourceCStr, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
            BOOST_LOG_TRIVIAL(error) << "Failed to compile fragment shader: " << infoLog;
            throw std::runtime_error("Failed to compile fragment shader");
        }
        id = glCreateProgram();
        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);
        glLinkProgram(id);
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(id, 512, nullptr, infoLog);
            BOOST_LOG_TRIVIAL(error) << "Failed to link shader program: " << infoLog;
            throw std::runtime_error("Failed to link shader program");
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
    Shader::~Shader()
    {
        glDeleteProgram(id);
    }
    void Shader::use()
    {
        glUseProgram(id);
    }
}