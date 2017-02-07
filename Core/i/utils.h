#ifndef __UTILS_H
#define __UTILS_H

#include <vector>
#include <string>
#include <set>

std::vector<std::string> split(std::string str, const std::string& delimiter);

std::string join(const std::vector<std::string>& parts, const std::string& delimiter);

std::set<std::string> shingle(const std::string& s, int shingleWidth = 4);

std::set<std::string> intersectionOf(const std::set<std::string>& setA, const std::set<std::string>& setB);

std::set<std::string> unionOf(const std::set<std::string>& setA, const std::set<std::string>& setB);

#endif
