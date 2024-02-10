#ifndef PERFECTNUMBER_H
#define PERFECTNUMBER_H

#pragma once

#include <vector>

class PerfectNumber
{
public:
    PerfectNumber();
    ~PerfectNumber();

    std::vector<size_t> findFactors(std::size_t n, bool bSort = false);
    bool isPerfect(std::size_t n);
    std::vector<size_t> findNPerfects(const std::size_t N, const std::size_t max_iterations = 1e9, const bool bPrintProgress = false);


    void printFactors(const std::vector<size_t>& factors) const;

private:

};

#endif