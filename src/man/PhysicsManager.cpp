#include <man/PhysicsManager.h>

#include <utils/global.h>
#include <utils/console.h>
#include <iostream>

#include <man/EntityManager.h>

PhysicsManager::PhysicsManager(size_t typeId) : ComponentManager(typeId)
{
    components.reserve(maxEntitiesCount);
    PhysicsComponent::typeId = typeId;
    CollideBoxComponent::typeId = typeId;
}

PhysicsManager::~PhysicsManager()
{
}

bool PhysicsManager::collision(const CollideBoxComponent& box, const CollideBoxComponent& box2) const
{
    return (box.x < box2.x + box2.w && box.x + box.w > box2.x    &&    box.y < box2.y + box2.h && box.y + box.h > box2.y) ? true : false;
}

const CollideBoxComponent& PhysicsManager::changeBox(char option, const PhysicsComponent& phy, const CollideBoxComponent& box) const
{
    static CollideBoxComponent s_box(0);

    /*s_box.w = box.w;
    s_box.h = box.h;

    s_box.x = phy.x + phy.vx * (option == 'x' ? 1 : 0);
    s_box.y = phy.y + phy.vy * (option == 'y' ? 1 : 0);*/

    return s_box;
}

void PhysicsManager::update(EntityManager& entityManager)
{
    for (size_t i = 0; i < components.size(); ++i)
    {
        auto& cmp = *reinterpret_cast<PhysicsComponent*>(components[i]);
        auto& box = entityManager.getComponent<CollideBoxComponent>(cmp.idEntity);
        
        {
            if (box.idEntity == 0) continue;

            for (size_t j = 0; j < components.size(); ++j)
            {
                auto& cmp2 = *reinterpret_cast<PhysicsComponent*>(components[j]);
                auto& box2 = entityManager.getComponent<CollideBoxComponent>(cmp2.idEntity);

                if (box2.idEntity == 0)  continue;
                if (i==j) continue;

                // Colision x
                /*if (collision(changeBox('x', cmp, box), box2))
                {
                    cmp.vx = 0;
                }

                // Colision y
                if (collision(changeBox('y', cmp, box), box2))
                {
                    cmp.vy = 0;
                }*/
            }
        }

        //mover todo

        auto& ren = entityManager.getComponent<RenderComponent>(cmp.idEntity);

        {
            if (ren.idEntity == 0) continue;
            if (i == 0)
            {
                Console::Gotoxy(0, 0);
                printf("float %ui", (unsigned int)cmp.vx);
            }
            ren.x += (unsigned int) cmp.vx;
            //ren.y += cmp.vy;
        }

        {
            if (box.idEntity == 0) continue;

            //box.x += cmp.vx;
            //box.y += cmp.vy;
        }

        //cmp.x += cmp.vx;
        //cmp.y += cmp.vy;

    }
}