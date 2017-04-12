#define IEEE_FLT uint32_t

//typedef struct INT_FRACT;
typedef struct {int32_t real; uint32_t fraction;} INT_FRACT;

IEEE_FLT IeeeEncode(INT_FRACT num);

IEEE_FLT IeeeMult(IEEE_FLT a, IEEE_FLT b);

IEEE_FLT IeeeAdd(IEEE_FLT a, IEEE_FLT b);