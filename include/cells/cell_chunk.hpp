#ifndef CELLCHUNK_HPP
#define CELLCHUNK_HPP

#include <cells/cell.hpp>
#include <render_handler.hpp>

class CellChunk {
private:
public:
	Cell* cells;
	uint32_t width;
	uint32_t height;
	uint32_t area;

	CellChunk(uint32_t width, uint32_t height);
	~CellChunk();

	Cell* getCell(uint32_t index);
	Cell* getCell(uint32_t x, uint32_t y);

	void setCell(uint32_t index, Cell cell);
	void setCell(uint32_t x, uint32_t y, Cell cell);

	void update();
	void render(RenderHandler* renderh);

	void updateSand(uint32_t x, uint32_t y, Cell* cell);
};

#endif