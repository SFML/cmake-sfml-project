#pragma once
#include "tools/CodeGenerator.h"
#include "tools/TrajectoryManager.h"
#include "ui/ITool.h"
#include <memory>

struct Code: public ITool {
    std::shared_ptr<CodeGenerator> generator;
    std::shared_ptr<TrajectoryManager> manager;
    void render() override;
};