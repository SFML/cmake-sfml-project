#include "tools/CodeGenerator.h"
#include "common/Pose2d.h"
#include <format>

std::string formatPose(const Pose2d& pose) {
return std::format("{{{}, {}, {}}}", pose.position.x(), pose.position.y(), pose.rotation);
}

std::string CodeGenerator::generateCode(const std::vector<Pose2d>& poses) {
    std::string output;
    if (not poses.empty()) {
        output += std::format("std::shared_ptr<Trajectory> trajectory = TrajectoryBuilderFactory::create({})\n", formatPose(poses[0]));
        for (int i = 1; i < poses.size(); i++) {
            output+=std::format("\t.to({})\n", formatPose(poses[i]));
        }
        output+="\t.build();\n";
    }
    return output;
}