#include "ui/tools/Code.h"
#include "imgui.h"
#include <GLFW/glfw3.h>

void Code::render() {
    std::string code = generator->generateCode(manager->poses);
    ImGui::Begin("Code");
    ImGui::BeginChild("Output");
    if (ImGui::Button("Copy")) {
        glfwSetClipboardString(nullptr, code.c_str());
    }
    ImGui::Separator();
    ImGui::TextWrapped(code.c_str());
    ImGui::EndChild();
    ImGui::End();
}