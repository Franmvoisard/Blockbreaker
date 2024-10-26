#pragma once
#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
using namespace sf;

class GameObject : public Drawable, public Transformable
{
    public:
        GameObject(Vector2f position, float rotation, Vector2f scale, const std::shared_ptr<Drawable>& drawable);

        ~GameObject() override;
        virtual void Tick();
        std::shared_ptr<Drawable> m_drawable;
        void draw(RenderTarget& target, RenderStates states) const override;
};