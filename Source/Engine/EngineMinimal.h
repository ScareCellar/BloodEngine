#pragma once

//standard library
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <list>
#include <cstdlib>
#include <random>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <filesystem>

//third-party library
#include <SDL3/SDL.h>
#include <fmod.hpp>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

//physics
#include "Source/Physics/ICollidable.h"

//core
#include "Source/Core/File.h"
#include "Source/Core/Logger.h"
#include "Source/Core/Random.h"
#include "Source/Core/Singleton.h"
#include "Source/Core/StringHelper.h"
#include "Source/Core/Time.h"
#include "Source/Core/Json.h"

//framwork
#include "Source/Framework/Object.h"
#include "Source/Framework/Game.h"
#include "Source/Framework/Scene.h"
#include "Source/Framework/Actor.h"

//math
#include "Source/Math/MathUtils.h"
#include "Source/Math/Transform.h"
#include "Source/Math/Vector2.h"
#include "Source/Math/Vector3.h"

//resources
#include "Source/Resources/Resource.h"
#include "Source/Resources/ResourceManager.h"


#include "Source/Core/Factory.h"