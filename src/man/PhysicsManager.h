#pragma once

#include <man/ComponentManager.h>

#include <cmp/PhysicsComponent.h>
#include <cmp/CollideBoxComponent.h>
#include <cmp/RenderComponent.h>

class PhysicsManager : public ComponentManager
{
public:
    PhysicsManager(size_t idType);
    ~PhysicsManager();

    void update(EntityManager& entityManager) override;

    bool collision(const CollideBoxComponent& box, const CollideBoxComponent& box2) const;
    const CollideBoxComponent& changeBox(char option, const PhysicsComponent& phy, const CollideBoxComponent& box) const;
};