#include "../Headers/dragontreasure.h"

DragonTreasure::DragonTreasure() { setType(Utility::Type::DragonTreasure); }

bool DragonTreasure::permeable() { return true; }

char DragonTreasure::draw() { return 'G'; }

Utility::Effect DragonTreasure::collected() { return Utility::Effect::DragonTreasure; }