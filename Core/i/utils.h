#ifndef __UTILS_H
#define __UTILS_H

#include <vector>
#include <string>
#include <set>

std::vector<std::string> split(std::string str, const std::string& delimiter);

std::string join(const std::vector<std::string>& parts, const std::string& delimiter);

template<typename T>
std::set<T> shingle(const T& s, int shingleWidth = 4);

template<typename T>
std::set<T> intersectionOf(const std::set<T>& setA, const std::set<T>& setB);

template<typename T>
std::set<T> unionOf(const std::set<T>& setA, const std::set<T>& setB);

#include "utils.ipp"

#endif
