#ifndef SPACEWORKS_GRAPHICS_SHADER_HPP
#define SPACEWORKS_GRAPHICS_SHADER_HPPz
#include <filesystem>
namespace graphics
{
    class Shader
    {
    public:
        Shader(std::filesystem::path vertexShaderPath, std::filesystem::path fragmentShaderPath);
        ~Shader();
        void use();
    private:
        int id;
    };
}
#endif