#include "spiral_matrix.h"

namespace spiral_matrix {

    enum Direction : uint8_t {
        Right,
        Down,
        Left,
        Up
    };

    Direction next_dir(Direction dir) {
        return static_cast<Direction>((static_cast<uint8_t>(dir) + 1) % 4);
    }
    
    std::vector<std::vector<uint32_t>> spiral_matrix(uint16_t size) {
        if(size == 1) {
            return {{1}};
        }
        std::vector<std::vector<uint32_t>> out{size, std::vector<uint32_t>(size, 0)};
        
        int n;

        for(n = 1; n <= size; n++) {
            out[0][n-1] = n;
        }


        // spiral side lengths follow: 1 size side, 2 (size - 1) sides, 2 (size - 2) sides, ... , 2 1 sides
        Direction dir = Direction::Down;
        int x = size - 1, y = 0;
        for(int sg_size = size-1; sg_size > 0; sg_size--) {
            for(int i = 0; i < 2; i++) {
                for (int j = 0; j < sg_size; j++, n++) {
                    switch(dir) {
                        case Direction::Right:
                            x += 1;
                            break;

                        case Direction::Down:
                            y += 1;
                            break;

                        case Direction::Left:
                            x -= 1;
                            break;

                        case Direction::Up:
                            y -= 1;
                            break;
                    }

                    out[y][x] = n;
                }

                dir = next_dir(dir);
            }
        }

        return out;
    }

}  // namespace spiral_matrix
