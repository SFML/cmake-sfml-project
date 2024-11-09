#pragma once
#include "tools/TrajectoryManager.h"
#include "ui/ITool.h"
#include <memory>

struct Editor: public ITool {
    std::shared_ptr<TrajectoryManager> manager;
    Editor(const std::shared_ptr<TrajectoryManager>& manager): manager{manager} {}
    void render() override;
};