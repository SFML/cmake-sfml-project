#include "App.h"
#include "Display.h"
#include "SceneRenderer.h"
#include "SplineSequence.h"
#include "TrajectoryManager.h"
#include "common/Pose2d.h"
#include <memory>

App::App() {
    manager = std::make_shared<TrajectoryManager>();
    renderer = std::make_shared<SceneRenderer>(manager);
    display = std::make_shared<Display>(800, 800, renderer);
    manager->points.push_back(Pose2d::Zero());
    sequence = std::make_shared<SplineSequence>(manager);

    sequence->listeners.push_back(this);
    display->menus.push_back(sequence);
}

void App::run() {
    while (display->update()) {

    }
}

void App::onMutate() {
    display->updateScene();
}