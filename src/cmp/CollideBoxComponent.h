#pragma once

#include <cmp/Component.h>

class CollideBoxComponent : public Component
{
public:
    CollideBoxComponent(size_t idEntity) : Component(idEntity) {}
    float x = 0, y = 0, w = 0, h = 0;
    inline static size_t typeId = 0;
};