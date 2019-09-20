#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#include <iostream>
#include <cassert>

template<class T>
class maxheap {

using value_type = T;
using size_type = size_t;

public:
    maxheap(size_type cap) : _size(0), _capacity(cap) {
        _data = new value_type[_capacity + 1]; 
    }
    maxheap(value_type* array, int n) : _size(n), _capacity(n) {
        _data = new value_type[_capacity + 1];
        for (size_type i = 0; i < _capacity; ++i) {
            _data[i+1] = array[i];
        }
        for (size_type i=n/2; i>1; --i) {
            percolateUp(i);
        }
    }
    size_type size() { return _size; }
    size_type capacity() { return _capacity; }
    bool empty() { return _size == 0; }
    void insert(value_type val) {
        if (_size == _capacity) {
            _capacity *= 2;
            value_type* old_data = _data;
            _data = new value_type[_capacity + 1];
            for (size_type i = 1; i <= _size; ++i) {
                _data[i] = old_data[i];
            }
            delete[] old_data;
        }
        _data[++_size] = val;
        percolateUp(_size);
    }
    value_type extractMax() {
        assert(_size > 0);
        value_type val = _data[1];
        _data[1] = _data[_size--];
        percolateDown(1);
        return val;
    }

private:
    void percolateUp(size_type k) {
        assert(k <= _size);
        value_type val = _data[k];
        while (k > 1 && _data[k/2] < val) {
            _data[k] = _data[k/2];
            k /= 2;
        }
        _data[k] = val;
    }
    void percolateDown(size_type k) {
        if (_size <= 1) {
            return;
        }
        value_type val = _data[k];
        while (2*k <= _size) {
            size_type child = 2*k;
            if (child+1 <= _size && _data[child+1] > _data[child]) {
                child++;
            }
            if (val > _data[child]) {
                break;
            } 
            _data[k] = _data[child];
            k = child;
        }
        _data[k] = val;
    }
private:
    value_type* _data;
    size_type _size;
    size_type _capacity;
};

#endif