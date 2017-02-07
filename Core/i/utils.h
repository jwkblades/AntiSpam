#ifndef __UTILS_H
#define __UTILS_H

#include <vector>
#include <string>

std::vector<std::string> split(std::string str, const std::string& delimiter);

std::string join(const std::vector<std::string>& parts, const std::string& delimiter);

#endif
