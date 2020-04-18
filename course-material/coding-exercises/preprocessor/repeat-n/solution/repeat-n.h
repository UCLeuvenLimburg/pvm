#ifndef REPEAT_N_H
#define REPEAT_N_H

#define REPEAT_N_AUX2(N, VAR)   for ( unsigned _i##VAR = 0; _i##VAR != N; ++_i##VAR )
#define REPEAT_N_AUX(N, VAR)    REPEAT_N_AUX2(N, VAR)
#define REPEAT_N(N)             REPEAT_N_AUX(N, __COUNTER__)

#endif
