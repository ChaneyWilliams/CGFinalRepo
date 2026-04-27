#include <BlockGame/FireTest.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterFireTestScript(Canis::App& _app)
    {
        REGISTER_PROPERTY(scriptConf, BlockGame::FireTest, maxIntensity);
        REGISTER_PROPERTY(scriptConf, BlockGame::FireTest, hiddenObject);

        DEFAULT_CONFIG(scriptConf, BlockGame::FireTest);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::FireTest);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, FireTest)

    void FireTest::Create() {}

    void FireTest::Ready() {
        if(hiddenObject){
            hiddenObject->active = false;
        }
    }

    void FireTest::Destroy() {}

    void FireTest::Update(float _dt) {
        PointLight point = entity.GetComponent<PointLight>();
        point.intensity = maxIntensity;
    }
}
