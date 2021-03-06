#pragma once

#include <iostream>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <memory>

#include "Debugging/Logging/Log.h"

/**
 * Simple shortcut for querying individual bits
 */
#define BIT(x) (1 << x)

#define JOTUNN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)