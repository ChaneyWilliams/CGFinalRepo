#include <BlockGame/FlyCam.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/InputManager.hpp>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterFlyCamScript(Canis::App &_app)
    {
        // REGISTER_PROPERTY(scriptConf, BlockGame::FlyCam, exampleProperty);

        DEFAULT_CONFIG(scriptConf, BlockGame::FlyCam);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::FlyCam);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, FlyCam)

    void FlyCam::Create() {}

    void FlyCam::Ready() {}

    void FlyCam::Destroy() {}

    void FlyCam::Update(float _dt)
    {
        InputManager &input = entity.scene.GetInputManager();

        auto &transform = entity.GetComponent<Canis::Transform>();

        float velocity = m_Speed * _dt;

        glm::vec3 position = transform.position;

        glm::vec3 forward = glm::vec3(0, 0, -1);
        glm::vec3 right = glm::vec3(1, 0, 0);
        glm::vec3 up = glm::vec3(0, 1, 0);

        // Movement (WASD)
        if (input.GetKey(Key::W))
            position += forward * velocity;
        if (input.GetKey(Key::S))
            position -= forward * velocity;
        if (input.GetKey(Key::A))
            position -= right * velocity;
        if (input.GetKey(Key::D))
            position += right * velocity;

        if (input.GetKey(Key::Q))
            position += up * velocity;
        if (input.GetKey(Key::E))
            position -= up * velocity;

        transform.position = position;


        transform.rotation = glm::vec3(0.0f);
    }
}
