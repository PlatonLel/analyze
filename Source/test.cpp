#include <Linalg.h>
#include <Complex.h>
#include <string>

int main() {
    linalg::Matrix<char> m({{'a', 'b'}, {'c','d'}});
    linalg::Matrix<char> m2({{1.2,2.2,4.2,5.2}, {1.2,2.2,4.2,5.2}});
//    m = m2;
    std::cout << m2;
    Complex c(1,2.5);
    Complex c2;
    std::cout << c;
    std::cin >> c2;
    std::cout << c2;
}
