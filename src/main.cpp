#include <iostream>

#include <utils/debug.h>
#include <utils/input.h>
#include <utils/console.h>

#include <man/RenderManager.h>
#include <man/PhysicsManager.h>
#include <man/EntityManager.h>

int main()
{   
    EntityManager entityManager;
    entityManager.addManager<RenderManager>();
    entityManager.addManager<PhysicsManager>();

    size_t entity0 = entityManager.addEntity();
    size_t entity1 = entityManager.addEntity();

    {
        auto& renCmp = entityManager.addComponent<RenderComponent>(entity0);
        renCmp.x = 5;
        renCmp.y = 5;
        renCmp.c = 'P';

        auto& phyCmp = entityManager.addComponent<PhysicsComponent>(entity0);
        phyCmp.x = 5;
        phyCmp.y = 5;
        phyCmp.vx = 0;

        auto& boxCmp = entityManager.addComponent<CollideBoxComponent>(entity0);
        boxCmp.x = 5;
        boxCmp.y = 5;
        boxCmp.w = 1;
        boxCmp.y = 0;
    }

    {
        auto& renCmp = entityManager.addComponent<RenderComponent>(entity1);
        renCmp.x = 10;
        renCmp.y = 5;
        renCmp.c = 'W';

        auto& phyCmp = entityManager.addComponent<PhysicsComponent>(entity1);
        phyCmp.x = 10;
        phyCmp.y = 5;
        phyCmp.vx = 0;
        
        auto& boxCmp = entityManager.addComponent<CollideBoxComponent>(entity1);
        boxCmp.x = 10;
        boxCmp.y = 5;
        boxCmp.w = 0;
        boxCmp.y = 0;
    }

    while (!Input::isKeyPressed(VK_ESCAPE))
    {
        Console::Clear();
        entityManager.update();
    }

    return 0;
}