/* Copyright (C) 2020 Kalray */

#define TLS_LD(x)                                  \
  ({                                               \
    int *__result;                                \
    extern void *__tls_get_addr (void *);          \
    __asm__ ("pcrel %0 = @gotaddr()\n\t"           \
             ";;\n\t"                              \
             "addd %0 = %0, @tlsld(" #x ")\n\t"    \
             ";;\n\t"                              \
         : "=r" (__result));                       \
    __result = (int *) __tls_get_addr (__result); \
    __asm__ ("addd %0 = %0, @dtpoff(" #x ")\n\t"   \
             ";;\n\t"                              \
         : "=r" (__result));                       \
    __result; })


#define TLS_GD(x)                                  \
  ({                                               \
    int *__result;                                 \
    extern void *__tls_get_addr (void *);          \
    __asm__ ("pcrel %0 = @gotaddr()\n\t"           \
             ";;\n\t"                              \
             "addd %0 = %0, @tlsgd(" #x ")\n\t"    \
             ";;\n\t"                              \
         : "=r" (__result));                       \
    (int *) __tls_get_addr (__result); })

#define TLS_LE(x)                                  \
  ({                                               \
    int *__result;                                 \
    __asm__ ("addd %0 = $r13, @tlsle(" #x ")\n\t"  \
             ";;\n\t"                              \
         : "=r" (__result));                       \
    __result; })


#define TLS_IE(x) \
  ({                                               \
    int *__result;                                 \
    __asm__ ("pcrel %0 = @gotaddr()\n\t"           \
             ";;\n\t"                              \
             "addd %0 = %0, @tlsie(" #x ")\n\t"    \
             ";;\n\t"                              \
         : "=r" (__result));                       \
     __result; })
