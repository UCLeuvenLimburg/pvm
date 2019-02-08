#ifndef REWRITE_H
#define REWRITE_H

#include <vector>
#include <set>
#include <string>
#include <algorithm>


void swapperdeswapperdeswap(int& p, int& q);
void quotrest(int x, int y, int& q, int& r);
int& min(int& p, int& q, int& r);
int& max(int& p, int& q, int& r);
void minmax(int& p, int& q, int& r, int*& minimum, int*& maximum);
void swap_min_and_max(int& p, int& q, int& r);
bool is_palindrome(const std::vector<int>& ns);
std::vector<int> crop(const std::vector<int>& ns, unsigned n);
void rotate(std::vector<int>& ns, int delta);
void trim(std::string& str);
void uniq(std::vector<int>& ns);

#endif