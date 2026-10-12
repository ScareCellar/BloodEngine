#pragma once
#include "Source/Framework/Game.h"
#include "Source/Renderer/Font.h"
#include "Source/Renderer/Text.h"
#include "Event/Observer.h"

class SpaceGame : public sc::Game, public sc::IObserver {
public:

	enum class GameState {
		Initialize,
		Title,
		StartGame,
		StartRound,
		Game,
		PlayerDead,
		GameOver
	};

public:
	SpaceGame() = default;

	bool Initialize() override;

	void Update(float dt) override;
	void Draw(class sc::Renderer& renderer) override;

	void Shutdown() override;

	void OnPlayerDestroyed();

	void OnNotify(const sc::Event& event) override;
	
private:
	GameState m_gamestate = GameState::Initialize;

	void SpawnEnemy();

	float m_enemySpawnTimer{ 0 };
	float m_spawnTime{ 4 };

	float m_stateTimer{ 0 };

	std::unique_ptr<sc::Text> m_titleText;
	std::unique_ptr<sc::Text> m_scoreText;
	std::unique_ptr<sc::Text> m_livesText;

	// Inherited via IObserver
};
