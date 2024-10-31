#pragma once
#include <vector>

#include "GameObject.h"

class GameObjectManager
{
public:
    static std::vector<std::shared_ptr<GameObject>>& GetObjects();
    static void Add(const std::shared_ptr<GameObject>& gameObject);

private:
    static std::vector<std::shared_ptr<GameObject>> m_gameObjects;
};
