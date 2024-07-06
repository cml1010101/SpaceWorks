#ifndef SPACEWORKS_BLOCKS_BLOCK_HPP
#define SPACEWORKS_BLOCKS_BLOCK_HPP
#include <SpaceWorks/graphics/Shader.hpp>
namespace blocks
{
    class Block
    {
    public:
        Block();
        ~Block();
        void draw();
    private:
        graphics::Shader shader;
    };
}
#endif