#pragma once

struct ITool {
    virtual ~ITool() = default;
    virtual void render() = 0;
};