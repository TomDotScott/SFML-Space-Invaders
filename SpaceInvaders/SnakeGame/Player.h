#pragma once
#include <iostream>

#include "Entity.h"

class Player final : public Entity {
public:
	explicit Player(std::string& _fileName) { LoadTexture(_fileName); std::cout << "PLAYER CONSTRUCTED"; };
	void Update();
	
};

