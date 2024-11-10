#include "ui/tools/Editor.h"
#include "imgui.h"
#include <format>
#include "IconsFontAwesome6.h"

void Editor::render() {
    ImGui::Begin("Splines", nullptr);
    ImGui::BeginChild("Poses");
    for (int i = 0; i < manager->poses.size(); i++) {
        Pose2d& point = manager->poses[i];
        ImGui::PushID(i);

        ImGui::SeparatorText(std::format("Point {}", i).c_str());

        ImGui::SetNextItemWidth(75);
        ImGui::InputDouble("X", &point.position.x());
        
        ImGui::SameLine();
        ImGui::SetNextItemWidth(75);
        ImGui::InputDouble("Y", &point.position.y());

        ImGui::SameLine();
        ImGui::SetNextItemWidth(75);
        ImGui::InputDouble("RAD", &point.rotation);
        
        ImGui::SameLine();

        if (i <= 0) {
            ImGui::BeginDisabled();
        }
        if (ImGui::Button(ICON_FA_CHEVRON_UP)) {
            std::swap(manager->poses[i], manager->poses[i-1]);
        }
        if (i <= 0) {
            ImGui::EndDisabled();
        }
        ImGui::SameLine();

        if (i >= manager->poses.size() -1) {
            ImGui::BeginDisabled();
        }
        if (ImGui::Button(ICON_FA_CHEVRON_DOWN)) {
            std::swap(manager->poses[i], manager->poses[i+1]);
        }
        if (i >= manager->poses.size() -1) {
            ImGui::EndDisabled();   
        }
        ImGui::SameLine();

        if (manager->poses.size() <= 1) {
            ImGui::BeginDisabled();
        }
        if (ImGui::Button(ICON_FA_XMARK)) {
                manager->poses.erase(manager->poses.begin() + i);
        }
        if (manager->poses.size() <= 1) {
            ImGui::EndDisabled();
        }
        ImGui::SameLine();

        if (ImGui::Button(ICON_FA_PLUS)) {
            manager->poses.insert(manager->poses.begin() + i + 1, Pose2d::Zero());
        }

        ImGui::PopID();
    }
    ImGui::EndChild();
    ImGui::End();
}