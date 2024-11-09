#pragma once
#include "tools/TrajectoryManager.h"
#include "ui/ITool.h"

struct Editor: public ITool {
    std::shared_ptr<TrajectoryManager> manager;
    void render() override;
};