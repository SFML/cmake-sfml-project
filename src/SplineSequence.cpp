#include "SplineSequence.h"
#include "common/Pose2d.h"
#include <imgui.h>
#include <format>

void SplineSequence::render() {
    ImGui::Begin("Splines", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::BeginChild("splines", ImVec2{400, 400});

    for (int i = 0; i < manager->points.size(); i++) {
        Pose2d& point = manager->points[i];
    
        ImGui::PushID(i);
        ImGui::SeparatorText(std::format("Point {}", i).c_str());

        ImGui::SetNextItemWidth(100);
        if (ImGui::InputDouble("X", &point.position.x())) {
            notifyListeners();
        }
        ImGui::SameLine();
        ImGui::SetNextItemWidth(100);
        if (ImGui::InputDouble("Y", &point.position.y())) {
            notifyListeners();
        }
        ImGui::SameLine();
        ImGui::SetNextItemWidth(100);
        if (ImGui::InputDouble("Angle", &point.rotation)) {
            notifyListeners();
        }
        
        if (i > 0) {
            if (ImGui::Button("Up")) {
                manager->swap(i, i-1);
                notifyListeners();
            }
            ImGui::SameLine();
        }

        if (i < manager->points.size() -1) {
            if (ImGui::Button("Down")) {
                manager->swap(i, i+1);
                notifyListeners();
            }
            ImGui::SameLine();
        }

        if (manager->points.size() > 1) {
            if (ImGui::Button("Remove")) {
                manager->remove(i);
                notifyListeners();
            }
            ImGui::SameLine();
        }

        if (ImGui::Button("New")) {
            manager->add(i+1);
            notifyListeners();
        }

        ImGui::PopID();
    }
    ImGui::EndChild();
    ImGui::End();
}