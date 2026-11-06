
#include <string>

#pragma once
namespace Mini
{
    class Texture
    {
        public:
        Texture(const std::string& name) 
        {
            name_ = name;
        }
        ~Texture() = default;

        private:
            std::string name_;

    };
}