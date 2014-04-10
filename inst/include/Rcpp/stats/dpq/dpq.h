#ifndef Rcpp__stats__dpq__dpq_h
#define Rcpp__stats__dpq__dpq_h

#include <Rcpp/stats/dpq/macros.h>

namespace Rcpp {
namespace stats {

// D

template <int RTYPE, bool NA, typename T, typename F>
class D0
    : public Rcpp::SugarVectorExpression<REALSXP, NA, D0<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  D0(F f_, const VEC_TYPE &vec_, bool log_) : f(f_), vec(vec_), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  int log;
};

template <int RTYPE, bool NA, typename T, typename F>
class D1
    : public Rcpp::SugarVectorExpression<REALSXP, NA, D1<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  D1(F f_, const VEC_TYPE &vec_, double p0_, bool log_)
      : f(f_), vec(vec_), p0(p0_), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], p0, log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0;
  int log;
};

template <int RTYPE, bool NA, typename T, typename F>
class D2
    : public Rcpp::SugarVectorExpression<REALSXP, NA, D2<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  D2(F f_, const VEC_TYPE &vec_, double p0_, double p1_, bool log_)
      : f(f_), vec(vec_), p0(p0_), p1(p1_), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], p0, p1, log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0, p1;
  int log;
};

template <int RTYPE, bool NA, typename T, typename F>
class D3
    : public Rcpp::SugarVectorExpression<REALSXP, NA, D3<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  D3(F f_, const VEC_TYPE &vec_, double p0_, double p1_, double p2_, bool log_)
      : f(f_), vec(vec_), p0(p0_), p1(p1_), p2(p2_), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], p0, p1, p2, log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0, p1, p2;
  int log;
};

// P

template <int RTYPE, bool NA, typename T, typename F>
class P0
    : public Rcpp::SugarVectorExpression<REALSXP, NA, P0<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  P0(F f_, const VEC_TYPE &vec_, bool lower_tail = true, bool log_ = false)
      : f(f_), vec(vec_), lower(lower_tail), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], lower, log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  int lower, log;
};

template <int RTYPE, bool NA, typename T, typename F>
class P1
    : public Rcpp::SugarVectorExpression<REALSXP, NA, P1<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  P1(F f_, const VEC_TYPE &vec_, double p0_, bool lower_tail = true,
     bool log_ = false)
      : f(f_), vec(vec_), p0(p0_), lower(lower_tail), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], p0, lower, log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0;
  int lower, log;
};

template <int RTYPE, bool NA, typename T, typename F>
class P2
    : public Rcpp::SugarVectorExpression<REALSXP, NA, P2<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  P2(F f_, const VEC_TYPE &vec_, double p0_, double p1_, bool lower_tail = true,
     bool log_ = false)
      : f(f_), vec(vec_), p0(p0_), p1(p1_), lower(lower_tail), log(log_) {}

  inline double operator[](int i) const {
    return f(vec[i], p0, p1, lower, log);
  }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0, p1;
  int lower, log;
};

template <int RTYPE, bool NA, typename T, typename F>
class P3
    : public Rcpp::SugarVectorExpression<REALSXP, NA, P3<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  P3(F f_, const VEC_TYPE &vec_, double p0_, double p1_, double p2_,
     bool lower_tail = true, bool log_ = false)
      : f(f_), vec(vec_), p0(p0_), p1(p1_), p2(p2_), lower(lower_tail),
        log(log_) {}

  inline double operator[](int i) const {
    return f(vec[i], p0, p1, p2, lower, log);
  }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0, p1, p2;
  int lower, log;
};

// Q

template <int RTYPE, bool NA, typename T, typename F>
class Q0
    : public Rcpp::SugarVectorExpression<REALSXP, NA, Q0<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  Q0(F f_, const VEC_TYPE &vec_, bool lower_tail = true, bool log_ = false)
      : f(f_), vec(vec_), lower(lower_tail), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], lower, log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  int lower, log;
};

template <int RTYPE, bool NA, typename T, typename F>
class Q1
    : public Rcpp::SugarVectorExpression<REALSXP, NA, Q1<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  Q1(F f_, const VEC_TYPE &vec_, double p0_, bool lower_tail = true,
     bool log_ = false)
      : f(f_), vec(vec_), p0(p0_), lower(lower_tail), log(log_) {}

  inline double operator[](int i) const { return f(vec[i], p0, lower, log); }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0;
  int lower, log;
};

template <int RTYPE, bool NA, typename T, typename F>
class Q2
    : public Rcpp::SugarVectorExpression<REALSXP, NA, Q2<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  Q2(F f_, const VEC_TYPE &vec_, double p0_, double p1_, bool lower_tail = true,
     bool log_ = false)
      : f(f_), vec(vec_), p0(p0_), p1(p1_), lower(lower_tail), log(log_) {}

  inline double operator[](int i) const {
    return f(vec[i], p0, p1, lower, log);
  }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0, p1;
  int lower, log;
};

template <int RTYPE, bool NA, typename T, typename F>
class Q3
    : public Rcpp::SugarVectorExpression<REALSXP, NA, Q3<RTYPE, NA, T, F>> {
public:
  using VEC_TYPE = VectorBase<RTYPE, NA, T>;

  Q3(F f_, const VEC_TYPE &vec_, double p0_, double p1_, double p2_,
     bool lower_tail = true, bool log_ = false)
      : f(f_), vec(vec_), p0(p0_), p1(p1_), p2(p2_), lower(lower_tail),
        log(log_) {}

  inline double operator[](int i) const {
    return f(vec[i], p0, p1, p2, lower, log);
  }

  inline int size() const { return vec.size(); }

private:
  F f;
  const VEC_TYPE &vec;
  double p0, p1, p2;
  int lower, log;
};

} // stats
} // Rcpp

#define RCPP_DPQ_0(__NAME__, __D__, __P__, __Q__)                              \
  namespace Rcpp {                                                             \
  struct D0_##__NAME__ {                                                       \
    inline double operator()(double x, bool log) const {                       \
      return __D__(x, log);                                                    \
    }                                                                          \
  };                                                                           \
  struct P0_##__NAME__ {                                                       \
    inline double operator()(double x, bool lower, bool log) const {           \
      return __P__(x, lower, log);                                             \
    }                                                                          \
  };                                                                           \
  struct Q0_##__NAME__ {                                                       \
    inline double operator()(double x, bool lower, bool log) const {           \
      return __Q__(x, lower, log);                                             \
    }                                                                          \
  };                                                                           \
  template <int RTYPE, bool NA, typename T, typename F = D0_##__NAME__>        \
  inline stats::D0<RTYPE, NA, T, F>                                            \
  d##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, bool log = false) {     \
    return stats::D0<RTYPE, NA, T, F>(D0_##__NAME__(), x, log);                \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = P0_##__NAME__>        \
  inline stats::P0<RTYPE, NA, T, F>                                            \
  p##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, bool lower = true,      \
              bool log = false) {                                              \
    return stats::P0<RTYPE, NA, T, F>(P0_##__NAME__(), x, lower, log);         \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = Q0_##__NAME__>        \
  inline stats::Q0<RTYPE, NA, T, F>                                            \
  q##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, bool lower = true,      \
              bool log = false) {                                              \
    return stats::Q0<RTYPE, NA, T, F>(Q0_##__NAME__(), x, lower, log);         \
  }                                                                            \
  }

#define RCPP_DPQ_1(__NAME__, __D__, __P__, __Q__)                              \
  namespace Rcpp {                                                             \
  struct D1_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, bool log) const {            \
      return __D__(x, p0, log);                                                \
    }                                                                          \
  };                                                                           \
  struct P1_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, bool lower,                  \
                             bool log) const {                                 \
      return __P__(x, p0, lower, log);                                         \
    }                                                                          \
  };                                                                           \
  struct Q1_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, bool lower,                  \
                             bool log) const {                                 \
      return __Q__(x, p0, lower, log);                                         \
    }                                                                          \
  };                                                                           \
  template <int RTYPE, bool NA, typename T, typename F = D1_##__NAME__>        \
  inline stats::D1<RTYPE, NA, T, F>                                            \
  d##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0,              \
              bool log = false) {                                              \
    return stats::D1<RTYPE, NA, T, F>(D1_##__NAME__(), x, p0, log);            \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = P1_##__NAME__>        \
  inline stats::P1<RTYPE, NA, T, F>                                            \
  p##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0,              \
              bool lower = true, bool log = false) {                           \
    return stats::P1<RTYPE, NA, T, F>(P1_##__NAME__(), x, p0, lower, log);     \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = Q1_##__NAME__>        \
  inline stats::Q1<RTYPE, NA, T, F>                                            \
  q##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0,              \
              bool lower = true, bool log = false) {                           \
    return stats::Q1<RTYPE, NA, T, F>(Q1_##__NAME__(), x, p0, lower, log);     \
  }                                                                            \
  }

#define RCPP_DPQ_2(__NAME__, __D__, __P__, __Q__)                              \
  namespace Rcpp {                                                             \
  struct D2_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, double p1, bool log) const { \
      return __D__(x, p0, p1, log);                                            \
    }                                                                          \
  };                                                                           \
  struct P2_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, double p1, bool lower,       \
                             bool log) const {                                 \
      return __P__(x, p0, p1, lower, log);                                     \
    }                                                                          \
  };                                                                           \
  struct Q2_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, double p1, bool lower,       \
                             bool log) const {                                 \
      return __Q__(x, p0, p1, lower, log);                                     \
    }                                                                          \
  };                                                                           \
  template <int RTYPE, bool NA, typename T, typename F = D2_##__NAME__>        \
  inline stats::D2<RTYPE, NA, T, F>                                            \
  d##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0, double p1,   \
              bool log = false) {                                              \
    return stats::D2<RTYPE, NA, T, F>(D2_##__NAME__(), x, p0, p1, log);        \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = P2_##__NAME__>        \
  inline stats::P2<RTYPE, NA, T, F>                                            \
  p##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0, double p1,   \
              bool lower = true, bool log = false) {                           \
    return stats::P2<RTYPE, NA, T, F>(P2_##__NAME__(), x, p0, p1, lower, log); \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = Q2_##__NAME__>        \
  inline stats::Q2<RTYPE, NA, T, F>                                            \
  q##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0, double p1,   \
              bool lower = true, bool log = false) {                           \
    return stats::Q2<RTYPE, NA, T, F>(Q2_##__NAME__(), x, p0, p1, lower, log); \
  }                                                                            \
  }

#define RCPP_DPQ_3(__NAME__, __D__, __P__, __Q__)                              \
  namespace Rcpp {                                                             \
  struct D3_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, double p1, double p2,        \
                             bool log) const {                                 \
      return __D__(x, p0, p1, p2, log);                                        \
    }                                                                          \
  };                                                                           \
  struct P3_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, double p1, double p2,        \
                             bool lower, bool log) const {                     \
      return __P__(x, p0, p1, p2, lower, log);                                 \
    }                                                                          \
  };                                                                           \
  struct Q3_##__NAME__ {                                                       \
    inline double operator()(double x, double p0, double p1, double p2,        \
                             bool lower, bool log) const {                     \
      return __Q__(x, p0, p1, p2, lower, log);                                 \
    }                                                                          \
  };                                                                           \
  template <int RTYPE, bool NA, typename T, typename F = D3_##__NAME__>        \
  inline stats::D3<RTYPE, NA, T, F>                                            \
  d##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0, double p1,   \
              double p2, bool log = false) {                                   \
    return stats::D3<RTYPE, NA, T, F>(D3_##__NAME__(), x, p0, p1, p2, log);    \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = P3_##__NAME__>        \
  inline stats::P3<RTYPE, NA, T, F>                                            \
  p##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0, double p1,   \
              double p2, bool lower = true, bool log = false) {                \
    return stats::P3<RTYPE, NA, T, F>(P3_##__NAME__(), x, p0, p1, p2, lower,   \
                                      log);                                    \
  }                                                                            \
  template <int RTYPE, bool NA, typename T, typename F = Q3_##__NAME__>        \
  inline stats::Q3<RTYPE, NA, T, F>                                            \
  q##__NAME__(const Rcpp::VectorBase<RTYPE, NA, T> &x, double p0, double p1,   \
              double p2, bool lower = true, bool log = false) {                \
    return stats::Q3<RTYPE, NA, T, F>(Q3_##__NAME__(), x, p0, p1, p2, lower,   \
                                      log);                                    \
  }                                                                            \
  }

#endif
