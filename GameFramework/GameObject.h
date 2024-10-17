#pragma once
#include <SFML/System/Vector2.hpp>
using namespace sf;

class game_object
{
    public:
        virtual ~game_object() = default;
        game_object(Vector2f position, Vector2f rotation, Vector2f scale);
        Vector2f m_position;
        Vector2f m_scale;
        Vector2f m_rotation;
};
