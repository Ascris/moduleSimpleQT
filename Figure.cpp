#include "Figure.hpp"

Figure::Figure()
	:x(0), y(0), z(0), t(0) {
	fig_opt= Option();
}

Figure::Figure(int x1, int y1, int z1, int t1)
	:x(x1), y(y1), z(z1), t(t1) {
	fig_opt= Option();
}
