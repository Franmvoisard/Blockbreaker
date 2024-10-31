#include "GameObjectManager.h"


std::vector<std::shared_ptr<GameObject>> GameObjectManager::m_gameObjects;
std::vector<std::shared_ptr<GameObject>>& GameObjectManager::GetObjects()
{
    return m_gameObjects;
}
void GameObjectManager::Add(const std::shared_ptr<GameObject>& gameObject)
{
    m_gameObjects.push_back(gameObject);
}
