#pragma once

class MutationListener {
public:
    virtual ~MutationListener() = default;
    virtual void onMutate() = 0;
};