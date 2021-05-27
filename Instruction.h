#pragma once
#include "TransSet.h"

class Instruction {
private:
	int x_size, y_size, no_iter;
	bool is2d;
	int no_fract;
	std::vector<TransSet> fractals;
	std::vector<int> frames_morph;

public:
	Instruction() : x_size(0), y_size(0), no_iter(0), is2d(true), no_fract(0) {
		fractals = {};
		frames_morph = {};
	}

	Instruction(int x, int y, int n, int n_f, std::vector<TransSet> ts, std::vector<int> f_m) :
		x_size(x), y_size(y), no_iter(n), is2d(true), no_fract(n_f), fractals(ts), frames_morph(f_m) {};

	Points calculate_fractal(int f_n){
		Points pts = {};
		Point curr = Point(x_size / 2, y_size / 2);
		for (int i = 0; i < no_iter; i++) {
			Trans t = fractals[f_n].randomTranslation();
			curr = t.calculate(curr);
			pts.push_back(curr);
		}
		return pts;
	}

};