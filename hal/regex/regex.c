#include "hal_regex.h"
#include "lib_memory.h"
#include <regex.h>

struct sRegexHandle {
  regex_t re;
};

RegexHandle Regex_comp(const char *regexString) {
  struct sRegexHandle *handle = NULL;
  handle = Memory_calloc(1, sizeof(struct sRegexHandle));
  if (regcomp(&handle->re, regexString, 0) != 0) {
    Memory_free(handle);
    return NULL;
  }
  return handle;
}

int Regex_exec(RegexHandle handle, const char *text) {
  return regexec(&handle->re, text, 0, NULL, 0);
}

size_t Regex_error(RegexHandle handle, int errorCode, char *msg,
                   size_t msgLen) {
  return regerror(errorCode, &handle->re, msg, msgLen);
}

void Regex_free(RegexHandle handle) {
  regfree(&handle->re);
  Memory_free(handle);
}
