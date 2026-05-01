#include <BlockGame/NewFireAnim.hpp>
#include <Canis/AssetManager.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterNewFireAnimScript(Canis::App &_app)
    {
        // REGISTER_PROPERTY(scriptConf, BlockGame::NewFireAnim, exampleProperty);

        DEFAULT_CONFIG(scriptConf, BlockGame::NewFireAnim);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::NewFireAnim);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, NewFireAnim)

    void NewFireAnim::Create() {}

    void NewFireAnim::Ready() {}

    void NewFireAnim::Destroy() {}

    void NewFireAnim::Update(float _dt)
    {

        totalTime += _dt;
        if (totalTime > 1.0f)
            increment = (increment >= 31) ? 1 : increment + 1;

        i32 textureid = AssetManager::LoadTexture("assets/textures/fire_textures/fire_" + std::to_string(increment) + ".png");
        i32 materialid = entity.GetComponent<Canis::Material>().materialId;
        entity.GetComponent<Material>().materialFields.SetTexture("albedoFireMap", textureid);

        PointLight *point = &(entity.GetComponent<PointLight>());
        point->intensity = (sin(totalTime) * 0.5f + minIntensity) * maxIntensity;
    }
}
