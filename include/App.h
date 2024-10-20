#pragma once
#include "MutationListener.h"
#include "SceneRenderer.h"
#include "SplineSequence.h"
#include "TrajectoryManager.h"
#include "Display.h"
#include <memory>

class App: MutationListener {
private:
    std::shared_ptr<SceneRenderer> renderer;

    std::shared_ptr<TrajectoryManager> manager;
    std::shared_ptr<Display> display;

    std::shared_ptr<SplineSequence> sequence;
public:
    App();
    void run();
    void onMutate() override;
};