#pragma once

#include <string>
#include <memory>

#include "RealmUser.h"

class GameSession {
public:
	GameSession();
	~GameSession();

	enum class GameType
	{
		Public,
		Private
	};

	enum class GameState
	{
		NotReady,
		Open,
		Started
	};

	GameType m_type;
	GameState m_state;

	std::weak_ptr< RealmUser > m_owner;

	int32_t m_gameIndex;
	
	std::wstring m_gameName;
	std::wstring m_ownerName;
	std::wstring m_playerCount;

	std::string m_gameData;
	std::string m_description;

	std::string m_hostLocalAddr;
	std::string m_hostExternalAddr;
	int32_t m_hostPort;

	int8_t m_currentPlayers;
	int8_t m_maximumPlayers;
};

typedef std::shared_ptr< GameSession > sptr_game_session;