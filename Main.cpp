#include "Main.h"

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Text.h>

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
   SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(Main, HandleKeyDown));

   SharedPtr<Text> text(new Text(context_));
   text->SetText("Hello Devember 2015!");
   text->SetColor(Color::WHITE);
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

