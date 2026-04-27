#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class FireAnimation : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char* ScriptName = "BlockGame::FireAnimation";

        explicit FireAnimation(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

        float totalTime = 0.0f;
        float pulse = 0.5f;

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    };

    void RegisterFireAnimationScript(Canis::App& _app);
    void UnRegisterFireAnimationScript(Canis::App& _app);
}
