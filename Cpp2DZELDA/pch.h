#pragma once

#include "Defines.h"
#include "Enums.h"
#include "Types.h"
#include "Utils.h"
#include "Values.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <windows.h>
using namespace std;


#include <assert.h>

// C++20
#include <format>
#include <filesystem>
//namespace fs = std::filesystem;

#define _CRTDEBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#pragma comment(lib, "msimg32.lib")