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

        //animation stuff
        //totalTime keeps track of totalTime and some math is performed to move frames
        //pulse controls the light emitted by the shader
        float totalTime = 0.0f;
        float pulse = 0.5f;

        //the min and max the pointLight will go between
        float maxIntensity = 2.0f;
        float minIntensity = 1.0f;

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    };

    void RegisterFireAnimationScript(Canis::App& _app);
    void UnRegisterFireAnimationScript(Canis::App& _app);
}
