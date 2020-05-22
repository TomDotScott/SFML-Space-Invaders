#include "SoundManager.h"


SoundManager::SoundManager() {
	LoadSFX("Explosion");
	LoadSFX("AlienDeath");
	LoadSFX("Shoot");
	LoadMusic("Music");
}

void SoundManager::PlaySFX(const std::string& _sfxName) {
	m_sfx.setBuffer(m_sfxBuffer.at(_sfxName));
	m_sfx.play();
}

void SoundManager::PlayMusic(const std::string& _musicName) {
	m_music.setBuffer(m_musicBuffer.at(_musicName));
	m_music.play();
}

void SoundManager::StopMusic() {
	m_music.stop();
}

void SoundManager::LoadSFX(const std::string& _fileName) {
	auto newSound{ sf::SoundBuffer() };
	newSound.loadFromFile("Resources/Audio/" + _fileName + ".wav");
	m_sfxBuffer.insert(std::pair<std::string, sf::SoundBuffer>(_fileName, newSound));
}

void SoundManager::LoadMusic(const std::string& _fileName) {
	auto newSound{ sf::SoundBuffer() };
	newSound.loadFromFile("Resources/Audio/" + _fileName + ".wav");
	m_musicBuffer.insert(std::pair<std::string, sf::SoundBuffer>(_fileName, newSound));
}