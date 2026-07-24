#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T, int N>
class MultiArray {
	vector<int> _dims;
	vector<T> _datas;
public:
	MultiArray() {


		_dims.resize(N);
		for(int i = 0; i < N; ++i) _dims[i] = 0;

		_datas.resize(300);

	}
	~MultiArray() {

	}

	MultiArray(const vector<int> &dims, const vector<T> &data = vector<T>()) {
		if(data.size() == 0) {
			int dim_nums = 1;
			for(int i = 0; i < dims.size(); ++i) {
				dim_nums *= dims[i];
			}
			for(int i = 0; i < dim_nums;++i) {
				_datas.push_back(T());
			}
			_dims = dims;
		}
		else if(dims.size() == 0) {
			_datas = data;
			for(int i = 0; i < (N-1); ++i) {
				_dims.push_back(1);
			}
			_dims.push_back(data.size());
		}
		else {
			_dims = dims;
			_datas = data;
		}
	}

	void set(const vector<int> &idx, const T &val) {
		int base_index = 0;
		for (int i = 0; i < idx.size(); ++i) {
			base_index = base_index * _dims[i] + idx[i];
		}

		_datas[base_index] = val;

	}
	T& get(const vector<int> &idx){
		int base_index = 0;
		for (int i = 0; i < idx.size(); ++i) {
			base_index = base_index * _dims[i] + idx[i] - 1;
		}
		return _datas[base_index];
	}
	vector<int>& get_dims() {
		return _dims;
	}
};
