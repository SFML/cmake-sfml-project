#include <iostream>
#include <vector>

class BackgroundGrid {
private:
    int width;
    int height;
    std::vector<int> grid;

    bool isValidIndex(int x, int y) const {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    int calculateIndex(int x, int y) const {
        if (isValidIndex(x, y)) {
         return y * width + x;
        }
        else {
            std::cerr << "Error: Index out of range.\n";
        }
    }

public:
    BackgroundGrid(int w, int h) : width(w), height(h), grid(w * h, 0) {}

    void setCell(int x, int y, int value) {
        grid[calculateIndex(x,y)] = value;
    }

    int getCell(int x, int y) const {
        return grid[calculateIndex(x,y)];
    }

    bool isComplete() const {
        for (int value : grid) {
            if (value == 1) {
                return false;
            }
        }
        return true;
    }

};