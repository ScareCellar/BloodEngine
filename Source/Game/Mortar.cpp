#include "GamePCH.h"
#include "Mortar.h"

class RegisterMortar {
public: RegisterMortar() {
    blood::Factory::Instance().Register<Mortar>("Mortar");
}
}; RegisterMortar register_instance;



void Mortar::Update(float dt)
{
    dropTime -= dt;
    if (dropTime <= 0) {
        Explode(dt);
    }
}

void Mortar::Explode(float dt)
{
    //owner->destroyed = false;
    owner->GetComponent<blood::CircleCollider2D>()->active = true;
    owner->GetComponent<blood::SpriteRenderer>()->active = true;
    owner->transform.scale = 20.0f;
    owner->GetComponent<blood::CircleCollider2D>()->radius = 300.0f;
    explosionTime -= dt;
    
    if (explosionTime <= 0) {
        owner->GetComponent<blood::CircleCollider2D>()->radius /= 10;
        owner->destroyed = true;
    }
}

void Mortar::Read(const blood::json::value_t& value)
{
    Object::Read(value);

    JSON_READ(value, dropTime);
    JSON_READ(value, explosionTime);
}


void Mortar::OnCollision(blood::Actor* other)
{
   
}
