#include "Main.h"

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/StaticModel.h>

URHO3D_DEFINE_APPLICATION_MAIN(Main)

Main::Main(Context* context)
    :Application(context)
{
}

void Main::Setup(){
   engineParameters_["FullScreen"] = false;
   engineParameters_["WindowWidth"] = 800;
   engineParameters_["WindowHeight"] = 600;
}

void Main::Start(){
   CreateScene();

   SetupViewport();
   
   SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(Main, HandleKeyDown));

   SharedPtr<Text> text(new Text(context_));
   text->SetText("Hello Devember 2015!");
   text->SetFont(GetSubsystem<ResourceCache>()->GetResource<Font>("Fonts/Anonymous Pro.ttf"), 30);
   text->SetColor(Color(0.0f, 1.0f, 0.0f));
   text->SetHorizontalAlignment(HA_CENTER);
   text->SetVerticalAlignment(VA_CENTER);

   GetSubsystem<UI>()->GetRoot()->AddChild(text);
}

void Main::HandleKeyDown(StringHash event, VariantMap& eventData) {
    using namespace KeyDown;

    int key = eventData[P_KEY].GetInt();

    if (key == KEY_ESC) {
        engine_->Exit();
    }
}

void Main::CreateScene()
{
    ResourceCache* cache = GetSubsystem<ResourceCache>();

    scene_ = new Scene(context_);
    scene_->CreateComponent<Octree>();

    Node* lightNode = scene_->CreateChild("DirectionalLight");
    lightNode->SetDirection(Vector3(0.6f, -1.0f, 0.8f));
    Light* light = lightNode->CreateComponent<Light>();
    light->SetLightType(LIGHT_DIRECTIONAL);

    Node* node = scene_->CreateChild("ExampleModel");
    node->SetPosition(Vector3(0.0f, -0.5f, 0.0f));
    node->SetRotation(Quaternion(0.0f, 135.0f, 0.0f));
    StaticModel* object = node->CreateComponent<StaticModel>();
    object->SetModel(cache->GetResource<Model>("Models/ExampleModel.mdl"));
    object->SetMaterial(cache->GetResource<Material>("Materials/Material.xml"));

    cameraNode_ = scene_->CreateChild("Camera");
    cameraNode_->CreateComponent<Camera>();
    cameraNode_->SetPosition(Vector3(0.0f, 1.0f, -5.0f));
}

void Main::SetupViewport()
{
    Renderer* renderer = GetSubsystem<Renderer>();

    SharedPtr<Viewport> viewport(new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>()));
    renderer->SetViewport(0, viewport);
}
