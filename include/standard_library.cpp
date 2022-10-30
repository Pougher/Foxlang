#include "standard_library.hpp"

const char* STANDARD_FENV = \
    "extern library \"fenv.h\"\n"
    "\n"
    "extern function feclearexcept;\n"
    "extern function fegetenv;\n"
    "extern function fegetexceptflag;\n"
    "extern function fegetround;\n"
    "extern function feholdexcept;\n"
    "extern function feraiseexcept;\n"
    "extern function fesetenv;\n"
    "extern function fesetexceptflag;\n"
    "extern function fesetround;\n"
    "extern function fetestexcept;\n"
    "extern function feupdateenv;\n"
    "\n";
const char* STANDARD_FLOAT = \
    "extern library \"float.h\"\n"
    "\n"
    "extern variable FLT_MIN;\n"
    "extern variable DBL_MIN;\n"
    "extern variable LDBL_MIN;\n"
    "extern variable FLT_TRUE_MIN;\n"
    "extern variable DBL_TRUE_MIN;\n"
    "extern variable LDBL_TRUE_MIN;\n"
    "extern variable FLT_MAX;\n"
    "extern variable DBL_MAX;\n"
    "extern variable LDBL_MAX;\n"
    "extern variable FLT_ROUNDS;\n"
    "extern variable FLT_EVAL_METHOD;\n"
    "extern variable FLT_RADIX;\n"
    "extern variable FLT_DIG;\n"
    "extern variable DBL_DIG;\n"
    "extern variable LDBL_DIG;\n"
    "extern variable FLT_EPSILON;\n"
    "extern variable DBL_EPSILON;\n"
    "extern variable LDBL_EPSILON;\n"
    "extern variable FLT_MANT_DIG;\n"
    "extern variable DBL_MANT_DIG;\n"
    "extern variable LDBL_MANT_DIG;\n"
    "extern variable FLT_MIN_EXP;\n"
    "extern variable DBL_MIN_EXP;\n"
    "extern variable LDBL_MIN_EXPR;\n"
    "extern variable FLT_MIN_10_EXP;\n"
    "extern variable DBL_MIN_10_EXP;\n"
    "extern variable LDBL_MIN_10_EXP;\n"
    "extern variable FLT_MAX_EXP;\n"
    "extern variable DBL_MAX_EXP;\n"
    "extern variable LDBL_MAX_EXP;\n"
    "extern variable FLT_MAX_10_EXP;\n"
    "extern variable DBL_MAX_10_EXP;\n"
    "extern variable LDBL_MAX_10_EXP;\n"
    "extern variable DECIMAL_DIG;\n"
    "\n";
const char* STANDARD_INTTYPES = \
    "extern library \"inttypes.h\"\n"
    "\n"
    "extern type int8_t;\n"
    "extern type int16_t;\n"
    "extern type int32_t;\n"
    "extern type int64_t;\n"
    "extern type uint8_t;\n"
    "extern type uint16_t;\n"
    "extern type uint32_t;\n"
    "extern type uint64_t;\n"
    "extern type int_least8_t;\n"
    "extern type int_least16_t;\n"
    "extern type int_least32_t;\n"
    "extern type int_least64_t;\n"
    "extern type uint_least8_t;\n"
    "extern type uint_least16_t;\n"
    "extern type uint_least32_t;\n"
    "extern type uint_least64_t;\n"
    "extern type int_fast8_t;\n"
    "extern type int_fast16_t;\n"
    "extern type int_fast32_t;\n"
    "extern type int_fast64_t;\n"
    "extern type uint_fast8_t;\n"
    "extern type uint_fast16_t;\n"
    "extern type uint_fast32_t;\n"
    "extern type uint_fast64_t;\n"
    "extern type intptr_t;\n"
    "extern type uintptr_t;\n"
    "extern type intmax_t;\n"
    "extern type uintmax_t;\n"
    "\n"
    "extern variable INT8_MIN;\n"
    "extern variable INT16_MIN;\n"
    "extern variable INT32_MIN;\n"
    "extern variable INT64_MIN;\n"
    "extern variable UINT8_MIN;\n"
    "extern variable UINT16_MIN;\n"
    "extern variable UINT32_MIN;\n"
    "extern variable UINT64_MIN;\n"
    "extern variable INT_LEAST8_MIN;\n"
    "extern variable INT_LEAST16_MIN;\n"
    "extern variable INT_LEAST32_MIN;\n"
    "extern variable INT_LEAST64_MIN;\n"
    "extern variable UINT_LEAST8_MIN;\n"
    "extern variable UINT_LEAST16_MIN;\n"
    "extern variable UINT_LEAST32_MIN;\n"
    "extern variable UINT_LEAST64_MIN;\n"
    "extern variable INT_FAST8_MIN;\n"
    "extern variable INT_FAST16_MIN;\n"
    "extern variable INT_FAST32_MIN;\n"
    "extern variable INT_FAST64_MIN;\n"
    "extern variable UINT_FAST8_MIN;\n"
    "extern variable UINT_FAST16_MIN;\n"
    "extern variable UINT_FAST32_MIN;\n"
    "extern variable UINT_FAST64_MIN;\n"
    "extern variable INT8_MAX;\n"
    "extern variable INT16_MAX;\n"
    "extern variable INT32_MAX;\n"
    "extern variable INT64_MAX;\n"
    "extern variable UINT8_MAX;\n"
    "extern variable UINT16_MAX;\n"
    "extern variable UINT32_MAX;\n"
    "extern variable UINT64_MAX;\n"
    "extern variable INT_LEAST8_MAX;\n"
    "extern variable INT_LEAST16_MAX;\n"
    "extern variable INT_LEAST32_MAX;\n"
    "extern variable INT_LEAST64_MAX;\n"
    "extern variable UINT_LEAST8_MAX;\n"
    "extern variable UINT_LEAST16_MAX;\n"
    "extern variable UINT_LEAST32_MAX;\n"
    "extern variable UINT_LEAST64_MAX;\n"
    "extern variable INT_FAST8_MAX;\n"
    "extern variable INT_FAST16_MAX;\n"
    "extern variable INT_FAST32_MAX;\n"
    "extern variable INT_FAST64_MAX;\n"
    "extern variable UINT_FAST8_MAX;\n"
    "extern variable UINT_FAST16_MAX;\n"
    "extern variable UINT_FAST32_MAX;\n"
    "extern variable UINT_FAST64_MAX;\n"
    "extern variable INTPTR_MIN;\n"
    "extern variable UINTPTR_MIN;\n"
    "extern variable INTPTR_MAX;\n"
    "extern variable UINTPTR_MAX;\n"
    "extern variable INTMAX_MIN;\n"
    "extern variable UINTMAX_MIN;\n"
    "extern variable INTMAX_MAX;\n"
    "extern variable UINTMAX_MAX;\n"
    "\n";
const char* STANDARD_SIGNAL = \
    "extern library \"signal.h\"\n"
    "\n"
    "extern variable SIGABRT;\n"
    "extern variable SIGFPE;\n"
    "extern variable SIGILL;\n"
    "extern variable SIGINT;\n"
    "extern variable SIGSEGV;\n"
    "extern variable SIGTERM;\n"
    "extern variable SIGTRAP; // can be removed (platform dependant)\n"
    "\n"
    "extern function raise;\n"
    "extern function kill;\n"
    "extern function signal;\n"
    "\n";
const char* STANDARD_STDDEF = \
    "extern library \"stddef.h\"\n"
    "\n"
    "extern type size_t;\n"
    "extern type ptrdiff_t;\n"
    "\n";
const char* STANDARD_ERRNO = \
    "extern library \"errno.h\"\n"
    "\n"
    "extern variable errno;\n"
    "extern variable EDOM;\n"
    "extern variable ERANGE;\n"
    "extern variable EILSEQ;\n"
    "\n";
const char* STANDARD_WCHAR = \
    "extern library \"wchar.h\"\n"
    "\n"
    "extern type mbstate_t;\n"
    "extern type size_t;\n"
    "// extern type struct tm (add later)\n"
    "extern type wchar_t;\n"
    "extern type wint_t;\n"
    "\n"
    "extern variable NULL;\n"
    "extern variable WCHAR_MAX;\n"
    "extern variable WCHAR_MIN;\n"
    "extern variable WEOF;\n"
    "\n";
const char* STANDARD_UCHAR = \
    "extern library \"uchar.h\"\n"
    "\n"
    "extern variable __STD_UTF_16__\n"
    "extern variable __STD_UTF_32__\n"
    "\n"
    "extern function c16rtomb;\n"
    "extern function c32rtomb;\n"
    "extern function mbrtoc16;\n"
    "extern function mbrtoc32;\n"
    "\n";
const char* STANDARD_STDBOOL = \
    "extern library \"stdbool.h\"\n"
    "\n"
    "extern variable true;\n"
    "extern variable false;\n"
    "\n"
    "const let __bool_defined: bool = true;\n"
    "\n";
const char* STANDARD_TIME = \
    "extern function \"time.h\"\n"
    "\n"
    "extern function difftime;\n"
    "extern function time;\n"
    "extern function clock;\n"
    "extern function timespec_get;\n"
    "extern function asctime;\n"
    "extern function ctime;\n"
    "extern function strftime;\n"
    "extern function strptime;\n"
    "extern function wcsftime;\n"
    "extern function gmtime;\n"
    "extern function localtime;\n"
    "extern function mktime;\n"
    "\n"
    "extern variable CLOCKS_PER_SEC;\n"
    "extern variable TIME_UTC;\n"
    "\n"
    "extern type struct_tm;\n"
    "extern type time_t;\n"
    "extern type clock_t;\n"
    "extern type timespec;\n"
    "\n";
const char* STANDARD_ISO646 = \
    "extern library \"iso646.h\"\n"
    "\n"
    "extern variable and;\n"
    "extern variable and_eq;\n"
    "extern variable bitand;\n"
    "extern variable bitor;\n"
    "extern variable compl;\n"
    "extern variable not;\n"
    "extern variable not_eq;\n"
    "extern variable or;\n"
    "extern variable or_eq;\n"
    "extern variable xor;\n"
    "extern variable xor_eq;\n"
    "\n";
const char* STANDARD_STDALIGN = \
    "extern library \"stdalign.h\"\n"
    "\n"
    "extern function alignas;\n"
    "extern function alignof;\n"
    "\n"
    "extern variable __alignas_is_defined;\n"
    "extern variable __alignof_is_defined;\n"
    "\n";
const char* STANDARD_LOCALE = \
    "extern library \"locale.h\"\n"
    "\n"
    "extern function setlocale;\n"
    "extern function localeconv;\n"
    "\n";
const char* STANDARD_STDARG = \
    "extern library \"stdarg.h\"\n"
    "\n"
    "extern type va_list;\n"
    "\n"
    "extern function va_start;\n"
    "extern function va_arg;\n"
    "extern function va_end;\n"
    "extern function va_copy;\n"
    "\n";
const char* STANDARD_ASSERT = \
    "extern library \"assert.h\"\n"
    "\n"
    "extern function assert;\n"
    "\n";
const char* STANDARD_MATH = \
    "extern library \"math.h\"\n"
    "\n"
    "extern function abs;\n"
    "extern function labs;\n"
    "extern function llabs;\n"
    "extern function fabs;\n"
    "extern function div;\n"
    "extern function ldiv;\n"
    "extern function lldiv;\n"
    "extern function fmod;\n"
    "extern function remainder;\n"
    "extern function remquo;\n"
    "extern function fma;\n"
    "extern function fmax;\n"
    "extern function fmin;\n"
    "extern function fdim;\n"
    "extern function nan;\n"
    "extern function nanf;\n"
    "extern function nanl;\n"
    "extern function exp;\n"
    "extern function exp2;\n"
    "extern function expm1;\n"
    "extern function log;\n"
    "extern function log2;\n"
    "extern function log10;\n"
    "extern function log1p;\n"
    "extern function ilogb;\n"
    "extern function logb;\n"
    "extern function sqrt;\n"
    "extern function cbrt;\n"
    "extern function hypo;\n"
    "extern function pow;\n"
    "extern function sin;\n"
    "extern function cos;\n"
    "extern function tan;\n"
    "extern function asin;\n"
    "extern function acos;\n"
    "extern function atan;\n"
    "extern function tan2;\n"
    "extern function sinh;\n"
    "extern function cosh;\n"
    "extern function tanh;\n"
    "extern function asinh;\n"
    "extern function acosh;\n"
    "extern function atanh;\n"
    "extern function erf;\n"
    "extern function lgamma;\n"
    "extern function tgamma;\n"
    "extern function ceil;\n"
    "extern function floor;\n"
    "extern function trunc;\n"
    "extern function round;\n"
    "extern function lround;\n"
    "extern function llround;\n"
    "extern function nearbyint;\n"
    "extern function rint;\n"
    "extern function lrint;\n"
    "extern function llrint;\n"
    "extern function frexp;\n"
    "extern function ldexp;\n"
    "extern function modf;\n"
    "extern function scalbn;\n"
    "extern function scalbln;\n"
    "extern function nextafter;\n"
    "extern function nexttoward;\n"
    "extern function copysign;\n"
    "extern function fpclassify;\n"
    "extern function isfinite;\n"
    "extern function isinf;\n"
    "extern function isnan;\n"
    "extern function isnormal;\n"
    "extern function signbit;\n"
    "\n";
const char* STANDARD_LIMITS = \
    "extern library \"limits.h\"\n"
    "\n"
    "extern variable CHAR_BIT;\n"
    "extern variable SCHAR_MIN;\n"
    "extern variable SHRT_MIN;\n"
    "extern variable INT_MIN;\n"
    "extern variable LONG_MIN;\n"
    "extern variable LLONG_MIN;\n"
    "extern variable SCHAR_MAX;\n"
    "extern variable SHRT_MAX;\n"
    "extern variable INT_MAX;\n"
    "extern variable LONG_MAX;\n"
    "extern variable LLONG_MAX;\n"
    "extern variable UCHAR_MAX;\n"
    "extern variable USHRT_MAX;\n"
    "extern variable UINT_MAX;\n"
    "extern variable ULONG_MAX;\n"
    "extern variable ULLONG_MAX;\n"
    "\n"
    "extern variable FLT_MIN;\n"
    "extern variable DBL_MIN;\n"
    "extern variable LDBL_MIN;\n"
    "extern variable FLT_TRUE_MIN;\n"
    "extern variable DBL_TRUE_MIN;\n"
    "extern variable LDBL_TRUE_MIN;\n"
    "extern variable FLT_MAX;\n"
    "extern variable DBL_MAX;\n"
    "extern variable LDBL_MAX;\n"
    "extern variable FLT_ROUNDS;\n"
    "extern variable FLT_EVAL_METHOD;\n"
    "extern variable FLT_RADIX;\n"
    "extern variable FLT_DIG;\n"
    "extern variable DBL_DIG;\n"
    "extern variable LDBL_DIG;\n"
    "extern variable FLT_EPSILON;\n"
    "extern variable DBL_EPSILON;\n"
    "extern variable LDBL_EPSILON;\n"
    "extern variable FLT_MANT_DIG;\n"
    "extern variable DBL_MANT_DIG;\n"
    "extern variable LDBL_MANT_DIG;\n"
    "extern variable FLT_MIN_EXP;\n"
    "extern variable DBL_MIN_EXP;\n"
    "extern variable LDBL_MIN_EXPR;\n"
    "extern variable FLT_MIN_10_EXP;\n"
    "extern variable DBL_MIN_10_EXP;\n"
    "extern variable LDBL_MIN_10_EXP;\n"
    "extern variable FLT_MAX_EXP;\n"
    "extern variable DBL_MAX_EXP;\n"
    "extern variable LDBL_MAX_EXP;\n"
    "extern variable FLT_MAX_10_EXP;\n"
    "extern variable DBL_MAX_10_EXP;\n"
    "extern variable LDBL_MAX_10_EXP;\n"
    "extern variable DECIMAL_DIG;\n"
    "\n";
const char* STANDARD_SETJMP = \
    "extern library \"setjmp.h\"\n"
    "\n"
    "extern function setjmp;\n"
    "extern function longjmp;\n"
    "\n"
    "extern type jmp_buf;\n"
    "\n";
const char* STANDARD_STDNORETURN = \
    "extern library \"stdnoreturn.h\"\n"
    "\n"
    "extern variable _Noreturn;\n"
    "extern variable noreturn;\n"
    "\n";
const char* STANDARD_CTYPE = \
    "extern library \"ctype.h\"\n"
    "\n"
    "extern function isalnum;\n"
    "extern function isalpha;\n"
    "extern function islower;\n"
    "extern function isupper;\n"
    "extern function isdigit;\n"
    "extern function isxdigit;\n"
    "extern function iscntrl;\n"
    "extern function isgraph;\n"
    "extern function isspace;\n"
    "extern function isblank;\n"
    "extern function isprint;\n"
    "extern function ispunct;\n"
    "extern function tolower;\n"
    "extern function toupper;\n"
    "extern function iswalnum;\n"
    "extern function iswalpha;\n"
    "extern function iswupper;\n"
    "extern function iswlower;\n"
    "extern function iswupper;\n"
    "extern function iswdigit;\n"
    "extern function iswxdigit;\n"
    "extern function iswcntrl;\n"
    "extern function iswgraph;\n"
    "extern function iswspace;\n"
    "extern function iswblank;\n"
    "extern function iswprint;\n"
    "extern function iswpunct;\n"
    "extern function towlower;\n"
    "extern function towupper;\n"
    "extern function iswctype;\n"
    "extern function towctrans;\n"
    "extern function wctype;\n"
    "extern function wctrans;\n"
    "\n";
const char* STANDARD_STDINT = \
    "extern library \"stdint.h\"\n"
    "\n"
    "extern type int8_t;\n"
    "extern type int16_t;\n"
    "extern type int32_t;\n"
    "extern type int64_t;\n"
    "extern type uint8_t;\n"
    "extern type uint16_t;\n"
    "extern type uint32_t;\n"
    "extern type uint64_t;\n"
    "extern type int_least8_t;\n"
    "extern type int_least16_t;\n"
    "extern type int_least32_t;\n"
    "extern type int_least64_t;\n"
    "extern type uint_least8_t;\n"
    "extern type uint_least16_t;\n"
    "extern type uint_least32_t;\n"
    "extern type uint_least64_t;\n"
    "extern type int_fast8_t;\n"
    "extern type int_fast16_t;\n"
    "extern type int_fast32_t;\n"
    "extern type int_fast64_t;\n"
    "extern type uint_fast8_t;\n"
    "extern type uint_fast16_t;\n"
    "extern type uint_fast32_t;\n"
    "extern type uint_fast64_t;\n"
    "extern type intptr_t;\n"
    "extern type uintptr_t;\n"
    "extern type intmax_t;\n"
    "extern type uintmax_t;\n"
    "\n";
const char* STANDARD_STRING = \
    "extern library \"string.h\"\n"
    "\n"
    "extern function strcpy;\n"
    "extern function strncpy;\n"
    "extern function strcat;\n"
    "extern function strncat;\n"
    "extern function strxfrm;\n"
    "extern function strlen;\n"
    "extern function strcmp;\n"
    "extern function strncmp;\n"
    "extern function strcoll;\n"
    "extern function strchr;\n"
    "extern function strrchr;\n"
    "extern function strspn;\n"
    "extern function strcspn;\n"
    "extern function strpbrk;\n"
    "extern function strstr;\n"
    "extern function strtok;\n"
    "extern function strerror;\n"
    "extern function memset;\n"
    "extern function memcpy;\n"
    "extern function memmove;\n"
    "extern function memcmp;\n"
    "extern function memchr;\n"
    "extern function wstrcpy;\n"
    "extern function wstrncpy;\n"
    "extern function wstrcat;\n"
    "extern function wstrncat;\n"
    "extern function wstrxfrm;\n"
    "extern function wstrlen;\n"
    "extern function wstrcmp;\n"
    "extern function wstrncmp;\n"
    "extern function wstrcoll;\n"
    "extern function wstrchr;\n"
    "extern function wstrrchr;\n"
    "extern function wstrspn;\n"
    "extern function wstrcspn;\n"
    "extern function wstrpbrk;\n"
    "extern function wstrstr;\n"
    "extern function wstrtok;\n"
    "extern function wmemset;\n"
    "extern function wmemcpy;\n"
    "extern function wmemmove;\n"
    "extern function wmemcmp;\n"
    "extern function wmemchr;\n"
    "extern function mblen;\n"
    "extern function mbtowc;\n"
    "extern function wctomb;\n"
    "extern function mbstowcs;\n"
    "extern function wcstombs;\n"
    "extern function btowc;\n"
    "extern function wctob;\n"
    "extern function mbsinit;\n"
    "extern function mbrlen;\n"
    "extern function mbrtowc;\n"
    "extern function wcrtomb;\n"
    "extern function mbsrtowcs;\n"
    "extern function wcsrtombs;\n"
    "extern function atof;\n"
    "extern function atoi;\n"
    "extern function atol;\n"
    "extern function atoll;\n"
    "extern function strtof;\n"
    "extern function strtod;\n"
    "extern function strtold;\n"
    "extern function strtol;\n"
    "extern function strtoll;\n"
    "extern function strtoul;\n"
    "extern function strtoull;\n"
    "extern function wcstof;\n"
    "extern function wcstod;\n"
    "extern function wcstold;\n"
    "extern function wcstol;\n"
    "extern function wcstoll;\n"
    "extern function wcstoul;\n"
    "extern function wcstoull;\n"
    "\n";
const char* STANDARD_WCTYPE = \
    "extern library \"wctype.h\"\n"
    "\n"
    "extern function iswalnum;\n"
    "extern function iswalpha;\n"
    "extern function iswblank;\n"
    "extern function iswcntrl;\n"
    "extern function iswdigit;\n"
    "extern function iswgraph;\n"
    "extern function iswlower;\n"
    "extern function iswprint;\n"
    "extern function iswpunct;\n"
    "extern function iswspace;\n"
    "extern function iswupper;\n"
    "extern function iswxdigit;\n"
    "extern function towlower;\n"
    "extern function towupper;\n"
    "extern function iswctype;\n"
    "extern function towctrans;\n"
    "extern function wctrans;\n"
    "extern function wctype;\n"
    "\n"
    "extern type wctrans_t;\n"
    "extern type wctype_t;\n"
    "extern type wint_t;\n"
    "\n"
    "extern variable WEOF;\n"
    "\n";
const char* STANDARD_STDIO = \
    "extern library \"stdio.h\"\n"
    "\n"
    "extern function fopen;\n"
    "extern function freopen;\n"
    "extern function fflush;\n"
    "extern function fclose;\n"
    "extern function setbuf;\n"
    "extern function setvbuf;\n"
    "extern function fwide;\n"
    "extern function fread;\n"
    "extern function fwrite;\n"
    "extern function fgetc;\n"
    "extern function getc;\n"
    "extern function fgets;\n"
    "extern function fputc;\n"
    "extern function putc;\n"
    "extern function fputs;\n"
    "extern function getchar;\n"
    "extern function gets;\n"
    "extern function putchar;\n"
    "extern function puts;\n"
    "extern function ungetc;\n"
    "extern function fgetwc;\n"
    "extern function getwc;\n"
    "extern function fgetws;\n"
    "extern function fputwc;\n"
    "extern function putwc;\n"
    "extern function fputws;\n"
    "extern function getwchar;\n"
    "extern function putwchar;\n"
    "extern function ungetwc;\n"
    "extern function scanf;\n"
    "extern function fscanf;\n"
    "extern function sscanf;\n"
    "extern function vscanf;\n"
    "extern function vfscanf;\n"
    "extern function vsscanf;\n"
    "extern function printf;\n"
    "extern function fprintf;\n"
    "extern function sprintf;\n"
    "extern function snprintf;\n"
    "extern function vprintf;\n"
    "extern function vfprintf;\n"
    "extern function vsprintf;\n"
    "extern function vsnprintf;\n"
    "extern function perror;\n"
    "extern function wscanf;\n"
    "extern function fwscanf;\n"
    "extern function swscanf;\n"
    "extern function vwscanf;\n"
    "extern function vfwscanf;\n"
    "extern function vswscanf;\n"
    "extern function wprintf;\n"
    "extern function fwprintf;\n"
    "extern function swprinrf;\n"
    "extern function vwprintf;\n"
    "extern function vfwprintf;\n"
    "extern function vswprintf;\n"
    "extern function ftell;\n"
    "extern function ftello;\n"
    "extern function fseek;\n"
    "extern function fseeko;\n"
    "extern function fgetpos;\n"
    "extern function fsetpos;\n"
    "extern function rewind;\n"
    "extern function clearerr;\n"
    "extern function feof;\n"
    "extern function ferror;\n"
    "extern function remove;\n"
    "extern function rename;\n"
    "extern function tmpfile;\n"
    "extern function tmpnam;\n"
    "\n"
    "extern variable EOF;\n"
    "extern variable BUFSIZ;\n"
    "extern variable FILENAME_MAX;\n"
    "extern variable FOPEN_MAX;\n"
    "extern variable _IOFBF;\n"
    "extern variable _IOLBF;\n"
    "extern variable _IONBF;\n"
    "extern variable L_tmpnam;\n"
    "extern variable NULL;\n"
    "extern variable SEEK_CUR;\n"
    "extern variable SEEK_END;\n"
    "extern variable SEEK_SET;\n"
    "extern variable TMP_MAX;\n"
    "\n"
    "extern variable stdin;\n"
    "extern variable stdout;\n"
    "extern variable stderr;\n"
    "\n"
    "extern type FILE;\n"
    "extern type fpos_t;\n"
    "extern type size_t;\n"
    "\n";
const char* STANDARD_STDLIB = \
    "extern library \"stdlib.h\"\n"
    "\n"
    "extern function abort;\n"
    "extern function atexit;\n"
    "extern function exit;\n"
    "extern function getenv;\n"
    "extern function system;\n"
    "extern function abs;\n"
    "extern function div;\n"
    "extern function labs;\n"
    "extern function ldiv;\n"
    "extern function rand;\n"
    "extern function srand;\n"
    "extern function atof;\n"
    "extern function atoi;\n"
    "extern function atol;\n"
    "extern function strtod;\n"
    "extern function strtol;\n"
    "extern function strtoll;\n"
    "extern function strtoul;\n"
    "extern function bsearch;\n"
    "extern function qsort;\n"
    "extern function calloc;\n"
    "extern function malloc;\n"
    "extern function realloc;\n"
    "extern function free;\n"
    "extern function mblen;\n"
    "extern function mbtowc;\n"
    "extern function wctomb;\n"
    "extern function mbstowcs;\n"
    "extern function wcstombs;\n"
    "extern function arc4random;\n"
    "extern function arc4random_uniform;\n"
    "extern function arc4random_buf;\n"
    "extern funtion arc4random_stir;\n"
    "\n";

const char* STANDARD_LIB_FILES[NUM_STANDARD_FILES] = {
    STANDARD_FENV,
    STANDARD_FLOAT,
    STANDARD_INTTYPES,
    STANDARD_SIGNAL,
    STANDARD_STDDEF,
    STANDARD_ERRNO,
    STANDARD_WCHAR,
    STANDARD_UCHAR,
    STANDARD_STDBOOL,
    STANDARD_TIME,
    STANDARD_ISO646,
    STANDARD_STDALIGN,
    STANDARD_LOCALE,
    STANDARD_STDARG,
    STANDARD_ASSERT,
    STANDARD_MATH,
    STANDARD_LIMITS,
    STANDARD_SETJMP,
    STANDARD_STDNORETURN,
    STANDARD_CTYPE,
    STANDARD_STDINT,
    STANDARD_STRING,
    STANDARD_WCTYPE,
    STANDARD_STDIO,
    STANDARD_STDLIB,
};
