#include "Engine.h"
#include "Framework/Actor.h"

class Bullet : public blood::Actor{
public:
	Bullet(blood::Transform& transform, std::shared_ptr<blood::Model> model) : blood::Actor{ transform, model } {};

	
	void Update(float dt);
	
	float speed{ 2000.0f };

	// Inherited via Actor
	void OnCollision(Actor* other) override;

private:
	bool exploded = false;
};