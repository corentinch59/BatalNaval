#include "Lerping.h"

sf::Vector2f Lerp(sf::Vector2f from, sf::Vector2f to, float t)
{
    return from + (to - from) * t;
}