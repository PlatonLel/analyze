#include <Linalg.h>
#include <Complex.h>
#include "../Include/ComplexTest.h"
#include "../Include/MatrixTest.h"
#include <string>
#include <filesystem>
#include <gtest/gtest.h>


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

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

    return RUN_ALL_TESTS();
}
