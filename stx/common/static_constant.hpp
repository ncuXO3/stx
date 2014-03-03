#ifndef STX_COMMON_STATIC_CONSTANT_HPP_
#define STX_COMMON_STATIC_CONSTANT_HPP_

#define STX_STATIC_CONSTANT(type, var, value) \
    static const type var = value;

//  TODO:
//  enum { var = value }; // Old compilers without static const support.
//  static constexpr type var = value; // New compilers with constexpr support;

#endif // STX_COMMON_STATIC_CONSTANT_HPP_
