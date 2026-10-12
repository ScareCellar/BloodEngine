#include "GamePCH.h"
#include "Mortar.h"

class RegisterMortar {
public: RegisterMortar() {
    sc::Factory::Instance().Register<Mortar>("Mortar");
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
    owner->GetComponent<sc::CircleCollider2D>()->active = true;
    owner->GetComponent<sc::SpriteRenderer>()->active = true;
    owner->transform.scale = 20.0f;
    owner->GetComponent<sc::CircleCollider2D>()->radius = 300.0f;
    explosionTime -= dt;
    
    if (explosionTime <= 0) {
        owner->GetComponent<sc::CircleCollider2D>()->radius /= 10;
        owner->destroyed = true;
    }
}

void Mortar::Read(const sc::json::value_t& value)
{
    Object::Read(value);

    JSON_READ(value, dropTime);
    JSON_READ(value, explosionTime);
}


void Mortar::OnCollision(sc::Actor* other)
{
   
}
