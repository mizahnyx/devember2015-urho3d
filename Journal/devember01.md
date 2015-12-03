On the first day of Devember I've chosen the following for my personal project:
* Game Engine: [Urho3D](http://urho3d.github.io/) Urho3D was chosen for its portability across platforms, its reliance on proven open source game libraries and its closeness to the metal.
* Platform: Linux desktop with possibility to port to Windows desktop and other platforms later
* Language: C++. Urho3D supports also [AngelScript](http://www.angelcode.com/angelscript/) and [Lua](http://www.lua.org/). However for its portability and execution speed we choose C++11.

We assume to have the latest Urho3D sources (from [Urho3D Git repository](https://github.com/urho3d/Urho3D)) in a directory that we will call `$URHO3D_SOURCES`. Urho3D as a game engine, tends to be extremely stable due to its test-driven-development practices. So even if we get the latest snapshot, we are unlikely to experience stability problems.

With the following commands we build the engine:

```bash
cd $URHO3D_SOURCES
./cmake_generic.sh build
cd build
make
export $URHO3D_HOME=$URHO3D_SOURCES/build
```

The directory we built the engine in, will become our `$URHO3D_HOME` for scaffolding purposes. Namely, `$URHO3D_SOURCES/build`. This environment variable is used by the scaffolding Rake script. To scaffold we need a target directory for the project, that we'll call `$DEVEMBER2015_HOME`:

```bash
cd $URHO3D_SOURCES
rake scaffolding dir=$DEVEMBER2015_HOME project=Devember2015-Urho3D
cd $DEVEMBER2015_HOME
./cmake_generic.sh build
cd build
make
```

This will generate a basic app for us, who just invokes the interpreters to runa Ninja Snow War game. To run the app we issue the commands:

```bash
cd $DEVEMBER2015_HOME/bin
../build/bin/Main
```

At last, we create a basic `.gitignore` file with the following content:

```
build
```

Customizing the app into not using the interpreter and creating a basic C++ Urho3D app will be left to later entries.


[Repository URL](https://github.com/mizahnyx/devember2015-urho3d)
