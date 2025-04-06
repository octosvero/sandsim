#include <cells/cell_chunk.hpp>

CellChunk::CellChunk(uint32_t width, uint32_t height) {
	this->area = width * height;
	this->width = width;
	this->height = height;
	this->cells = new Cell[area];
}

CellChunk::~CellChunk() {
	delete[] cells;
}

Cell* CellChunk::getCell(uint32_t index) {
	return &cells[index];
}

Cell* CellChunk::getCell(uint32_t x, uint32_t y) {
	return &cells[x + y * width];
}

void CellChunk::setCell(uint32_t index, Cell cell) {
	cells[index] = cell;
}

void CellChunk::setCell(uint32_t x, uint32_t y, Cell cell) {
	cells[x + y * width] = cell;
}

void CellChunk::update() {
	for (int32_t x = 0; x < width; x++) {
		for (int32_t y = height - 1; y >= 0; y--) {
			Cell* cell = getCell(x, y);

			// No need to update air
			if (cell->id == CellID_Air)
				continue;

			// Update Cell
			switch (cell->id) {
				case CellID_Sand:
					updateSand(x, y, cell);
					break;
			}
		}
	}
}

void CellChunk::render(RenderHandler* renderh) {
	SDL_Renderer* renderer = renderh->getRenderer();

	// TODO: Add a surface to draw cells on
	
	for (int32_t i = 0; i < area; i++) {
		Cell* cell = getCell(i);

		// No need to draw air
		if (cell->id == CellID_Air)
			continue;

		// Set Cell color
		switch (cell->id) {
			case CellID_Sand:
				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
				break;
		}

		// Draw Cell
		uint32_t rx = i % width;
		uint32_t ry = i / width;

		SDL_RenderPoint(renderer, rx, ry);
	}
}

void CellChunk::updateSand(uint32_t x, uint32_t y, Cell* cell) {
	// Sand has nowhere to fall
	if (y == height - 1) {
		return;
	}

	Cell* cellSouth = getCell(x, y + 1);
	Cell* cellWest  = getCell(x - 1, y);
	Cell* cellEast  = getCell(x + 1, y);

	if (cellSouth->id == CellID_Air) {
		Cell air(CellID_Air);
		setCell(x, y + 1, *cell);
		setCell(x, y, air);
		return;
	}

	if (x > 0 && cellWest->id == CellID_Air) {
		Cell air(CellID_Air);
		setCell(x - 1, y, *cell);
		setCell(x, y, air);
		return;
	}

	if (x < width - 1 && cellEast->id == CellID_Air) {
		Cell air(CellID_Air);
		setCell(x + 1, y, *cell);
		setCell(x, y, air);
		return;
	}
}