#include "TrajectoryManager.h"
#include "common/Pose2d.h"
#include "pathing/TrajectoryBuilder.h"

std::shared_ptr<Trajectory> TrajectoryManager::getTrajectory() {
    if (!points.empty()) {
        TrajectoryBuilder builder = TrajectoryBuilderFactory::create(*points.begin());
        for (const Pose2d& point: points) {
            builder.to(point);
        }
        return builder.build();
    }
    return nullptr;
}

void TrajectoryManager::remove(int index) {
    points.erase(points.begin() + index);
}

void TrajectoryManager::swap(int a, int b) {
    std::swap(points[a], points[b]);
}

void TrajectoryManager::add(int index) {
    points.insert(points.begin() + index, Pose2d::Zero());
}
