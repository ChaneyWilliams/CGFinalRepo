#include <BlockGame/FireAnimation.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterFireAnimationScript(Canis::App &_app)
    {
        REGISTER_PROPERTY(scriptConf, BlockGame::FireAnimation, totalTime);
        REGISTER_PROPERTY(scriptConf, BlockGame::FireAnimation, pulse);

        DEFAULT_CONFIG(scriptConf, BlockGame::FireAnimation);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::FireAnimation);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, FireAnimation)

    void FireAnimation::Create() {}

    void FireAnimation::Ready() {}

    void FireAnimation::Destroy() {}

    void FireAnimation::Update(float _dt)
    {
        //I saw this on the website and sighed 
        //touche
        totalTime += _dt;
        auto &material = entity.GetComponent<Canis::Material>();
        material.color.a = 0.9f;
        material.materialFields.SetFloat("firePulse", pulse);
        material.materialFields.SetFloat("TIME", totalTime);
    }
}
