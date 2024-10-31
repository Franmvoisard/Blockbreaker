#pragma once
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
using namespace sf;

class GameObject : public Drawable, public Transformable
{
    public:
        GameObject(const std::shared_ptr<Drawable>& drawable, Vector2f position = Vector2f(0,0), float rotation = 0, Vector2f scale = Vector2f(1,1));
        ~GameObject() override;
        virtual void Tick();
        std::shared_ptr<Drawable> m_drawable;
        void draw(RenderTarget& target, RenderStates states) const override;
};