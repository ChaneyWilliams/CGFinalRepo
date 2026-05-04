#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class FoliageSpawner : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char* ScriptName = "BlockGame::FoliageSpawner";

        explicit FoliageSpawner(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}
        //basically get all the blocks tagged grass and randomly decide if they get grass, flower, or nothing
        //The blocks under stuff are tagged Dirt
        Canis::SceneAssetHandle flowerPrefab;
        Canis::SceneAssetHandle grassPrefab;

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    private:
        std::vector<Canis::Entity*> grassBlocks;
    };

    void RegisterFoliageSpawnerScript(Canis::App& _app);
    void UnRegisterFoliageSpawnerScript(Canis::App& _app);
}
