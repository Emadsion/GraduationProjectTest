#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg, bit)   (Reg) |=  (1 << (bit))
#define CLEAR_BIT(Reg, bit)   (Reg) &= (~(1 << (bit)))
#define TOG_BIT(Reg, bit)   (Reg) ^=  (1 << (bit))
#define GET_BIT(Reg, bit)   (((Reg) >> (bit)) & (1))

#endif
