#ifndef REGEX_HAL_H_
#define REGEX_HAL_H_

#include "hal_base.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef struct sRegexHandle *RegexHandle;

PAL_API RegexHandle Regex_comp(const char *regexString);
PAL_API int Regex_exec(RegexHandle handle, const char *text);
PAL_API size_t Regex_error(RegexHandle handle, int errorCode, char *msg,
                           size_t msgLen);
PAL_API void Regex_free(RegexHandle handle);

#ifdef __cplusplus
}
#endif
#endif
