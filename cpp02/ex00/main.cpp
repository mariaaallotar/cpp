
#include "Fixed.hpp"

int main() {
	Fixed v1;
	Fixed v2(3);
	Fixed v3(v1);
	Fixed v4(v2);

	v1 = v4;
}
