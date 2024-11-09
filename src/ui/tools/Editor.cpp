#include "ui/tools/Editor.h"
#include "imgui.h"
#include <format>

void Editor::render() {
    ImGui::Begin("Splines", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::BeginChild("Poses");
    for (int i = 0; i < manager->poses.size(); i++) {
        Pose2d& point = manager->poses[i];
    
        ImGui::PushID(i);
        ImGui::SeparatorText(std::format("Point {}", i).c_str());

        ImGui::SetNextItemWidth(100);
        ImGui::InputDouble("X", &point.position.x());
        
        ImGui::SameLine();
        ImGui::SetNextItemWidth(100);
        ImGui::InputDouble("Y", &point.position.y());

        ImGui::SameLine();
        ImGui::SetNextItemWidth(100);
        ImGui::InputDouble("Angle", &point.rotation);
        
        if (i > 0) {
            if (ImGui::Button("Up")) {
                std::swap(manager->poses[i], manager->poses[i-1]);
            }
            ImGui::SameLine();
        }

        if (i < manager->poses.size() -1) {
            if (ImGui::Button("Down")) {
                std::swap(manager->poses[i], manager->poses[i+1]);
            }
            ImGui::SameLine();
        }

        if (manager->poses.size() > 1) {
            if (ImGui::Button("Remove")) {
                manager->poses.erase(manager->poses.begin() + i);
            }
            ImGui::SameLine();
        }

        if (ImGui::Button("New")) {
            manager->poses.insert(manager->poses.begin() + i, Pose2d::Zero());
        }

        ImGui::PopID();
    }
    ImGui::EndChild();
    ImGui::End();
}