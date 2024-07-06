#ifndef SPACEWORKS_BLOCKS_BLOCKTYPE_HPP
#define SPACEWORKS_BLOCKS_BLOCKTYPE_HPP
#include <string>
#include <vector>
#include <SpaceWorks/graphics/Shader.hpp>
#include <glm/glm.hpp>
namespace blocks
{
    class BlockType
    {
    public:
        virtual std::string get_name() = 0;
        virtual std::vector<std::string> get_tags() = 0;
        virtual graphics::Shader get_shader() = 0;
        virtual glm::vec3 get_size() = 0;
    };
}
#endif