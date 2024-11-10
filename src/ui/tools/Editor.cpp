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

        ImGui::SetNextItemWidth(60);
        ImGui::InputDouble("X", &point.position.x(), 0, 0, "%.4f");
        
        ImGui::SameLine();
        ImGui::SetNextItemWidth(60);
        ImGui::InputDouble("Y", &point.position.y(), 0, 0, "%.4f");

        ImGui::SameLine();
        ImGui::SetNextItemWidth(60);
        ImGui::InputDouble("RAD", &point.rotation, 0, 0, "%.4f");
        
        ImGui::SameLine();

        ImGui::Text("|");

        ImGui::SameLine();

        bool disabled = false;

        disabled = i <= 0;
        if (disabled)
            ImGui::BeginDisabled();
        if (ImGui::Button(ICON_FA_CHEVRON_UP, {20, 0})) {
            std::swap(manager->poses[i], manager->poses[i-1]);
        }
        if (disabled)
            ImGui::EndDisabled();

        ImGui::SameLine();

        disabled = i >= manager->poses.size() -1;
        if (disabled)
            ImGui::BeginDisabled();
        if (ImGui::Button(ICON_FA_CHEVRON_DOWN, {20, 0})) {
            std::swap(manager->poses[i], manager->poses[i+1]);
        }
        if (disabled)
            ImGui::EndDisabled();
        ImGui::SameLine();

        disabled = manager->poses.size() <= 1;
        if (disabled)
            ImGui::BeginDisabled();
        ImGui::SetNextItemWidth(25);
        ImGui::PushStyleColor(ImGuiCol_Button, 0xFF0000DD);
        if (ImGui::Button(ICON_FA_XMARK, {20, 0})) {
                manager->poses.erase(manager->poses.begin() + i);
        }
        ImGui::PopStyleColor();
        if (disabled)
            ImGui::EndDisabled();
        ImGui::SameLine();

        ImGui::PushStyleColor(ImGuiCol_Button, 0xFF00DD00);
        if (ImGui::Button(ICON_FA_PLUS, {20, 0})) {
            manager->poses.insert(manager->poses.begin() + i + 1, Pose2d::Zero());
        }
        ImGui::PopStyleColor();

        ImGui::PopID();
    }
    ImGui::EndChild();
    ImGui::End();
}