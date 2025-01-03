#include <Linalg.h>
#include <Complex.h>
#include <string>
#include <filesystem>


int main() {
    linalg::Matrix<Complex> matrix = {
            { Complex(1.0, 1.1), Complex(2.0, 0.0), Complex(0.0, -1.0) },
            { Complex(0.1, 0.0), Complex(3.0, -3.0), Complex(1.0, 1.0) }
    };
//    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    linalg::Matrix<double> m = {{1.2,2.01,3.6},{1.023,2.6023,3.}};
//    std::cout << matrix;
    std::cout << linalg::load_matrix("s.txt");
}
