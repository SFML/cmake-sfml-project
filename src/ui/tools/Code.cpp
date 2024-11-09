#include "ui/tools/Code.h"
#include "imgui.h"
#include <GLFW/glfw3.h>

void Code::render() {
    std::string code = generator->generateCode(manager->poses);
    ImGui::Begin("Code");
    ImGui::BeginChild("Output");
    ImGui::TextWrapped(code.c_str());
    if (ImGui::Button("Copy")) {
        glfwSetClipboardString(nullptr, code.c_str());
    }
    ImGui::EndChild();
    ImGui::End();
}