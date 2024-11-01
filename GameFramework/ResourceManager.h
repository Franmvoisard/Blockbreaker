#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>

class ResourceManager
{
    public:
        static std::shared_ptr<sf::Texture> GetTextureById(const std::string& id);
        static void LoadTexture(const std::string& location, const std::string& id);
    private:
        static std::map<std::string , std::shared_ptr<sf::Texture>> m_textures;
};

