#ifndef Rcpp__Vector_h
#define Rcpp__Vector_h

#include <Rcpp/vector/00_forward.h>
#include <Rcpp/vector/SugarVectorExpression.h>
#include <Rcpp/vector/SugarMatrixExpression.h>

#include <Rcpp/vector/VectorOffset.h>
#include <Rcpp/vector/converter.h>
#include <Rcpp/vector/concat.h>
#include <Rcpp/vector/create.h>

#include <Rcpp/vector/name_proxy.h>
#include <Rcpp/vector/simple_name_proxy.h>
#include <Rcpp/vector/string_name_proxy.h>
#include <Rcpp/vector/generic_name_proxy.h>

#include <Rcpp/vector/simple_const_name_proxy.h>
#include <Rcpp/vector/string_const_name_proxy.h>
#include <Rcpp/vector/generic_const_name_proxy.h>

#include <Rcpp/vector/string_proxy.h>
#include <Rcpp/vector/const_string_proxy.h>
#include <Rcpp/vector/generic_proxy.h>
#include <Rcpp/vector/const_generic_proxy.h>

#include <Rcpp/vector/VectorOf.h>
#include <Rcpp/vector/impl/SimpleVector.h>
#include <Rcpp/vector/impl/CharacterVector.h>
#include <Rcpp/vector/impl/List.h>
#include <Rcpp/vector/impl/ExpressionVector.h>

#include <Rcpp/vector/is_materialized.h>
#include <Rcpp/vector/instantiation.h>

#include <Rcpp/String.h>
#include <Rcpp/NA_Proxy.h>

#include <Rcpp/vector/concat_free.h>

#include <Rcpp/vector/swap.h>
#include <Rcpp/vector/Demangler.h>

#include <Rcpp/vector/StrideIterator.h>
#include <Rcpp/vector/MatrixBase.h>
#include <Rcpp/vector/MatrixColumn.h>
#include <Rcpp/vector/MatrixRow.h>
#include <Rcpp/vector/Matrix.h>

#endif
