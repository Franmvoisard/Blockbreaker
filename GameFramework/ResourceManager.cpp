#include "ResourceManager.h"

#include <ostream>
#include <stdexcept>

std::map<std::string, std::shared_ptr<sf::Texture>> ResourceManager::m_textures;

std::shared_ptr<sf::Texture> ResourceManager::GetTextureById(const std::string& id)
{
    if (m_textures.find(id) != m_textures.end())
    {
        return m_textures[id];
    }
    throw std::exception("Resource not loaded.");
}

void ResourceManager::LoadTexture(const std::string& location, const std::string& id)
{
    const std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if(texture->loadFromFile(location))
    {
        m_textures[id] = texture;
    }
    else
    {
        throw std::runtime_error("Failed to load texture from location: " + location);
    }
}
