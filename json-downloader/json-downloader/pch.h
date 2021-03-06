// pch.h
#ifndef PCH_H
#define PCH_H

#include <cstdio>
#include <cstdlib>
#include <cwchar>

#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>

#include <algorithm>
#include <cctype>
#include <string>

// curl 
#include <curl/curl.h>

// json for modern c++
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// spdlog 
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


#endif //PCH_H