#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class FlyCam : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char *ScriptName = "BlockGame::FlyCam";

        explicit FlyCam(Canis::Entity &_entity) : Canis::ScriptableEntity(_entity) {}

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;

    private:
        float m_Speed = 5.0f;
        float m_MouseSensitivity = 0.1f;

        float m_Yaw = -90.0f;
        float m_Pitch = 0.0f;

        bool m_FirstMouse = true;
        float m_LastMouseX = 0.0f;
        float m_LastMouseY = 0.0f;
    };

    void RegisterFlyCamScript(Canis::App &_app);
    void UnRegisterFlyCamScript(Canis::App &_app);
}
