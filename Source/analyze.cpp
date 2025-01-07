#include <Linalg.h>
#include <Complex.h>
#include <iostream>

int main(int argc, char* argv[] ) {
    if (argc == 2) {
        try {
            linalg::analyze_matrix(argv[1]);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    } else if (argc != 1) {
        std::cerr << "Usage: " << argv[0] << " [matrix_file]" << std::endl;
        return 1;
    }
}
