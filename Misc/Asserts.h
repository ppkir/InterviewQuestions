#ifndef __Asserts__
#define __Asserts__

#include <assert.h>
#include <vector>
#include "Helpers.h"

namespace Asserts {

	template <typename T>
	static void AreEqual(T* x1, size_t x1len, T* x2, size_t x2len) {
		assert(x1len == x2len);
		for (size_t i = 0; i < x1len; i++) {
			assert(x1[i] == x2[i]);
		}
	}

	template <typename T>
	static void AreEqual(const std::vector<T>& expected, const std::vector<T>& actual) {
		assert(expected.size() == actual.size());
		for (size_t i = 0; i < expected.size(); i++) {
			assert(expected[i] == actual[i]);
		}
	}

	template <typename T>
	static void AreEqual(const std::vector<T>& expected, T* arr, size_t arrLen) {
		assert(expected.size() == arrLen);
		for (size_t i = 0; i < expected.size(); i++) {
			assert(expected[i] == arr[i]);
		}
	}

	template <typename T>
	static void AreEqual(T* arr, size_t arrLen, const std::vector<T>& actual) {
		AreEqual(actual, arr, arrLen);
	}

	template <typename T, typename U>
	static void AreEqual (const T& x, const U& y) {
		assert(x == y);
	}

	static void IsTrue(bool val) {
		assert(val);
	}

	static void IsFale(bool val) {
		assert(!val);
	}

	static void Fail() {
		assert(false);
	}
}

#endif