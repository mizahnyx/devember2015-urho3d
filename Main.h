#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>

using namespace Urho3D;

class Main : public Application {
   URHO3D_OBJECT(Main, Application);

public:
   Main(Context*);

   virtual void Setup();
   virtual void Start();
   virtual void Stop() {}

protected:
   SharedPtr<Scene> scene_;
   SharedPtr<Node> cameraNode_;

private:
   void CreateScene();
   void SetupViewport();
   void HandleKeyDown(StringHash,  VariantMap&);
};

