#pragma once
#include "Source/Framework/Game.h"
#include "Source/Renderer/Font.h"
#include "Source/Renderer/Text.h"

class SpaceGame : public blood::Game {
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
	void Draw(class blood::Renderer& renderer) override;

	void Shutdown() override;

	void OnPlayerDestroyed();

	
private:
	GameState m_gamestate = GameState::Initialize;

	void SpawnEnemy();

	float m_enemySpawnTimer{ 0 };
	float m_spawnTime{ 4 };

	float m_stateTimer{ 0 };

	std::unique_ptr<blood::Text> m_titleText;
	std::unique_ptr<blood::Text> m_scoreText;
	std::unique_ptr<blood::Text> m_livesText;
};
