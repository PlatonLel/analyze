#include <Linalg.h>
#include <Complex.h>
#include <string>

int main() {
    linalg::Matrix<Complex> matrix = {
            { Complex(1.0, 1.1), Complex(2.0, 0.0), Complex(0.0, -1.0) },
            { Complex(0.00001, 0.0), Complex(3.0, -348193641.0), Complex(1.0, 1.00912) }
    };
    linalg::Matrix<double> m = {{1.2,2.01,3.6},{1.023,2.6023,3.}};
    std::cout << matrix;

}
