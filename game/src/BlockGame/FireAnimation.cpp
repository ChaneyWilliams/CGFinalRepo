#include <BlockGame/FireAnimation.hpp>
#include <Canis/AssetManager.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/Debug.hpp>

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
        REGISTER_PROPERTY(scriptConf, BlockGame::FireAnimation, maxIntensity);
        REGISTER_PROPERTY(scriptConf, BlockGame::FireAnimation, minIntensity);

        DEFAULT_CONFIG(scriptConf, BlockGame::FireAnimation);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::FireAnimation);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, FireAnimation)

    void FireAnimation::Create() {
    }

    void FireAnimation::Ready() {

        //affects everything using that material
        //i32 textureid = AssetManager::LoadTexture("assets/textures/fire_textures/fire_" + std::to_string(1) + ".png");
        //i32 materialid = entity.GetComponent<Canis::Material>().materialId; 
        //MaterialAsset* material = AssetManager::GetMaterial(materialid);
        //material->albedoId = textureid;

        //affects just this object
        //i32 textureid = AssetManager::LoadTexture("assets/textures/fire_textures/fire_" + std::to_string(1) + ".png");
        //i32 materialid = entity.GetComponent<Canis::Material>().materialId; 
        //entity.GetComponent<Material>().materialFields.SetTexture("albedoFireMap", textureid);
    }

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


        //ever just start placing & and * to see if that'll fix something
        //it worked for once
        PointLight* point = &(entity.GetComponent<PointLight>());
        point->intensity = (sin(totalTime) * 0.5f + minIntensity) * maxIntensity;
    }
}
