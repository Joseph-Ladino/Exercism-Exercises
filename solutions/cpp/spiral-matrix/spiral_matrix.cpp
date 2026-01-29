#include "spiral_matrix.h"
#include <tuple>

namespace spiral_matrix {
    std::pair<int, int> rotate_dir(int x_dir, int y_dir) {
        return std::make_pair(-y_dir, x_dir);
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


        // spiral side group lengths follow: 1 size side, 2 (size - 1) sides, 2 (size - 2) sides, ... , 2 1 sides
        int x = size - 1, y = 0;
        int x_dir = 0, y_dir = 1;
        for(int sg_size = size-1; sg_size > 0; sg_size--) {
            for(int i = 0; i < 2; i++) {
                for (int j = 0; j < sg_size; j++, n++) {
                    x += x_dir;
                    y += y_dir;
                    out[y][x] = n;
                }

                std::tie(x_dir, y_dir) = rotate_dir(x_dir, y_dir);
            }
        }

        return out;
    }

}  // namespace spiral_matrix
