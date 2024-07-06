#ifndef SPACEWORKS_BLOCKS_BLOCK_HPP
#define SPACEWORKS_BLOCKS_BLOCK_HPP
#include <SpaceWorks/graphics/Shader.hpp>
#include <glm/glm.hpp>
namespace blocks
{
    class Block
    {
    public:
        Block(glm::vec3 position, graphics::Shader shader, uint64_t type);
        ~Block();
        uint64_t get_type();
        glm::vec3 get_position();
        void set_position(glm::vec3 position);
        virtual void render() = 0;
    private:
        graphics::Shader shader;
        glm::vec3 position;
        uint64_t type;
    };
}
#endif