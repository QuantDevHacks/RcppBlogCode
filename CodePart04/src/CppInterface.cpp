#include "NonmemberCppFcns.h"
#include <vector>
#include <Rcpp.h>     

// This seems to be optional...at least for Windows/Rtools:
// [[Rcpp::plugins(cpp17)]]

// Nonmember Function Interfaces:

// [[Rcpp::export]]
int rAdd(double x, double y)
{
  // Call the add(.) function in the reusable C++ code base:
  return add(x, y);
}

// [[Rcpp::export]]
Rcpp::NumericVector rSortVec(Rcpp::NumericVector v)
{
  // Transfer data from NumericVector to std::vector<double>
  auto stlVec = Rcpp::as<std::vector<double>>(v); 
  
  // Call the reusable sortVec(.) function, with the expected
  // std::vector<double> argument:
  stlVec = sortVec(stlVec);
  
  // Reassign the results from the vector<double> return object
  // to the same NumericVector v, using Rcpp::wrap(.):
  v = Rcpp::wrap(stlVec);
  
  // Return as an Rcpp::NumericVector:
  return v;
}

// C++17 example:
// [[Rcpp::export]]
int rProdLcmGcd(int m, int n)
{
  return prodLcmGcd(m, n);
}

/*
 Copyright <2020> <Daniel Hanson>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction, 
 including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
 subject to the following conditions:
 
 The above copyright notice and this permission 
 notice shall be included in all copies 
 or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
 FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
