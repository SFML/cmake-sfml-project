#include "tools/TrajectoryManager.h"
#include <pathing/TrajectoryBuilder.h>

std::shared_ptr<Trajectory> TrajectoryManager::generateTrajectory() {
    TrajectoryBuilder builder = TrajectoryBuilderFactory::create(poses[0]);
    for (int i = 1; i < poses.size(); i++) {
        builder.to(poses[i]);
    }
    return builder.build();
}