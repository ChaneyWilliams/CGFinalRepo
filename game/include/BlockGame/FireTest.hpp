#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class FireTest : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char* ScriptName = "BlockGame::FireTest";

        explicit FireTest(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

        float maxIntensity = 7.0f;
        Canis::Entity* hiddenObject = nullptr;

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    };

    void RegisterFireTestScript(Canis::App& _app);
    void UnRegisterFireTestScript(Canis::App& _app);
}
