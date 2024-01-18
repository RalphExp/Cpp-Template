#ifndef IFTHENELSE_HPP_
#define IFTHENELSE_HPP_

// primary template: yield the second argument by default and rely on
// a partial specialization to yield the third argument
// if COND is false

template <bool Cond, typename TrueType, typename FalseType>
struct IfThenElseT {
    using Type = TrueType;
};

template <typename TrueType, typename FalseType>
struct IfThenElseT<false, TrueType, FalseType> {
    using Type = FalseType;
};

template<bool Cond, typename TrueType, typename FalseType>
using IfThenElse = typename IfThenElseT<Cond, TrueType, FalseType>::Type; 

#endif