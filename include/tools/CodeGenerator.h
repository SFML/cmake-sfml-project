#pragma once
#include <common/Pose2d.h>

struct CodeGenerator {
    std::string generateCode(const std::vector<Pose2d>& poses);
};