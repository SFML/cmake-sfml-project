#include "ui/tools/Code.h"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include "IconsFontAwesome6.h"

void Code::render() {
    std::string code = generator->generateCode(manager->poses);
    ImGui::Begin("Code");
    ImGui::BeginChild("Output");
    ImGui::Text("Generated Code");
    ImGui::SameLine();
    if (ImGui::Button(ICON_FA_COPY)) {
        glfwSetClipboardString(nullptr, code.c_str());
    }
    ImGui::Separator();
    ImGui::TextWrapped(code.c_str());
    ImGui::EndChild();
    ImGui::End();
}