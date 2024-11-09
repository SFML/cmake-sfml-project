#pragma once
#include "backends/imgui_impl_glfw.h"
#include "ui/ITool.h"
#include <map>
#include <memory>
#include <string>

class Window {
private:
    GLFWwindow* window;
    std::map<std::string, bool> activated;
    std::map<std::string, std::shared_ptr<ITool>> tools;
public:
    Window();
    ~Window();
    void addTool(const std::string& name, const std::shared_ptr<ITool>& tool);
    bool render();
};