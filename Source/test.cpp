#include <Linalg.h>
#include <Complex.h>
#include <string>
#include <filesystem>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments!" << std::endl;
        return 1;
    }

    std::string file_name = argv[1];

    try {
        linalg::Matrix<Complex> matrix = linalg::load_matrix(file_name.c_str());
        if (matrix.empty()) {
            throw std::runtime_error("Nothing to analyze because the matrix is empty!");
        }

        std::cout << "The original matrix was read from file '" << file_name << "':\n";
        std::cout << matrix << std::endl;

        if (matrix.rows() != matrix.columns()) {
            std::cout << "Other analyses are not possible due to not squared matrix!\n";
            return 0;
        }

        std::cout << "Transposed matrix:\n" << linalg::transpose(matrix) << std::endl;

        double trace = 0.0;
        for (size_t i = 0; i < matrix.rows(); ++i) {
            trace += matrix(i, i).Real();
        }
        std::cout << "Trace: " << trace << std::endl;

        Complex determinant = matrix.det();
        std::cout << "Determinant: " << determinant << std::endl;

        if (determinant != 0) {
            std::cout << "Inverted matrix:\n" << linalg::invert(matrix) << std::endl;
        } else {
            std::cout << "Other analyses are not possible due to zero determinant!" << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
