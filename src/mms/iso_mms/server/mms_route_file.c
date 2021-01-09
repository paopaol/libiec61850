
#include "libiec61850_platform_includes.h"
#include "linked_list.h"
#include "mms_server.h"

struct sMmsRouteFileList {
  LinkedList list;
};

MmsRouteFileList MmsRouteFileList_create() {
  return (MmsRouteFileList)LinkedList_create();
}

void MmsRouteFileList_append(MmsRouteFileList fileList, const char *file) {
  LinkedList_add((LinkedList)fileList, (void *)strdup(file));
}

MmsRouteFileList MmsRouteFileList_getNext(MmsRouteFileList fileList) {
  return (MmsRouteFileList)LinkedList_getNext((LinkedList)fileList);
}

const char *MmsRouteFileList_getFile(MmsRouteFileList self) {
  return LinkedList_getData((LinkedList)self);
}

void MmsRouteFileList_destory(MmsRouteFileList fileList) {
  LinkedList_destroy((LinkedList)fileList);
}
