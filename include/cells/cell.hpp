#ifndef CELL_HPP
#define CELL_HPP

#include <cstdint>

enum CellID : uint32_t {
	CellID_Air = 0,
	CellID_Sand
};

class Cell {
private:
public:
	CellID id;
	// Implement other things like color later

	Cell();
	Cell(CellID id);
};

#endif