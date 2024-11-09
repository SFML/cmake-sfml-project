#pragma once
#include "ui/ITool.h"
#include <map>
#include <memory>
#include <string>

struct Window {
    std::map<std::string, std::shared_ptr<ITool>> tools;
    std::map<std::string, bool> activated;
    Window();
    ~Window();
    void render();
};