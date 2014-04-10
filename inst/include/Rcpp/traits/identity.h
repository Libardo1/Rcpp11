#ifndef Rcpp__traits__identity__h
#define Rcpp__traits__identity__h

namespace Rcpp {
namespace traits {

template<typename T>
struct identity { typedef T type; };

}
}

#endif
