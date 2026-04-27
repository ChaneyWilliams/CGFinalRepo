#include <BlockGame/FoliageSpawner.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/Debug.hpp>
#include <algorithm>
#include <cmath>
#include <random>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterFoliageSpawnerScript(Canis::App &_app)
    {
        REGISTER_PROPERTY(scriptConf, BlockGame::FoliageSpawner, grassPrefab);
        REGISTER_PROPERTY(scriptConf, BlockGame::FoliageSpawner, flowerPrefab);
        DEFAULT_CONFIG(scriptConf, BlockGame::FoliageSpawner);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::FoliageSpawner);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, FoliageSpawner)

    void FoliageSpawner::Create()
    {
    }

    void FoliageSpawner::Ready()
    {
        grassBlocks = entity.scene.GetEntitiesWithTag("Grass");

        std::random_device rd;
        std::mt19937 rng(rd());
        std::discrete_distribution<int> dist({12, 12, 75}); // flower, grass, nothing

        for (Entity *grass : grassBlocks)
        {

            int result = dist(rng);

            if (result == 0)
            {
                // I couldnt find how instaniating worked so i dug into FOGPI
                // and I just copy pasted the turret before it was changed to pooling
                std::vector<Canis::Entity *> loaded = entity.scene.Instantiate(flowerPrefab);
                Canis::Entity *projectile = nullptr;
                if (loaded.size() > 0)
                {
                    projectile = loaded[0];

                    if (projectile->HasComponent<Transform>())
                    {
                        Transform &transform = projectile->GetComponent<Transform>();
                        transform.position = grass->GetComponent<Transform>().GetGlobalPosition() + Canis::Vector3(0.0f, .5f, 0.0f);
                    }
                }
            }
            else if (result == 1)
            {
                // I couldnt find how instaniating worked so i dug into FOGPI
                // and I just copy pasted the turret before it was changed to pooling
                std::vector<Canis::Entity *> loaded = entity.scene.Instantiate(grassPrefab);
                Canis::Entity *projectile = nullptr;
                if (loaded.size() > 0)
                {
                    projectile = loaded[0];

                    if (projectile->HasComponent<Transform>())
                    {
                        Transform &transform = projectile->GetComponent<Transform>();
                        transform.position = grass->GetComponent<Transform>().GetGlobalPosition() + Canis::Vector3(0.0f, .5f, 0.0f);
                    }
                }
            }
            // else 2 → nothing
        }
    }

    void FoliageSpawner::Destroy() {}

    void FoliageSpawner::Update(float) {}
}
