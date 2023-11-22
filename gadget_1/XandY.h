#pragma once

class Variables { // користувацький тип даних, для збереження зчитаних параметрів пошуку по списку гаджетів, за розмірами

private:
	int x1 = 0;   // розміри для пошуку (поля класу)
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
public:
	Variables() { 
		x1 = 0;
		x2 = 0;
		y1 = 0;
		y2 = 0;
	}

	Variables(int xi, int xi2, int yi, int yi2) {
		x1 = xi;
		x2 = xi2;
		y1 = yi;
		y2 = yi2;
	}

	int GetVariable(int index)const { // метод класу, для отримання зчитаних параметрів
		if (index == 0) {
			return x1;
		}
		else if (index == 1) {
			return x2;
		}
		else if (index == 2) {
			return y1;
		}
		else if (index == 3) {
			return y2;
		}
	}
	void SetVariable(int xi, int xi2, int yi, int yi2) {// метод класу, для задання зчитаних параметрів
		x1 = xi;
		x2 = xi2;
		y1 = yi;
		y2 = yi2;
	}
};