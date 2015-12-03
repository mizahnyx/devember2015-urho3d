#pragma once

#include <Urho3D/Engine/Application.h>

using namespace Urho3D;

class Main : public Application {
   URHO3D_OBJECT(Main, Application);

public:
   Main(Context*);

   virtual void Setup();
   virtual void Start();
   virtual void Stop() {}

private:
   void HandleKeyDown(StringHash,  VariantMap&);
};


