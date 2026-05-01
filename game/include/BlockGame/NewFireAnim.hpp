#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class NewFireAnim : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char* ScriptName = "BlockGame::NewFireAnim";

        explicit NewFireAnim(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

        int increment = 1;
        float totalTime = 0.0f;

        float minIntensity = 1.0f;
        float maxIntensity = 1.0f;
        
        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    };

    void RegisterNewFireAnimScript(Canis::App& _app);
    void UnRegisterNewFireAnimScript(Canis::App& _app);
}
