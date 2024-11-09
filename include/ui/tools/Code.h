#pragma once
#include "tools/CodeGenerator.h"
#include "tools/TrajectoryManager.h"
#include "ui/ITool.h"
#include <memory>

struct Code: public ITool {
    std::shared_ptr<CodeGenerator> generator;
    std::shared_ptr<TrajectoryManager> manager;
    Code(const std::shared_ptr<CodeGenerator>& generator, const std::shared_ptr<TrajectoryManager>& manager): generator{generator}, manager{manager} {} 
    void render() override;
};