#ifndef __UNIONFS_FUSE_H__
#define __UNIONFS_FUSE_H__

extern int unionfs_main(int, char**);
#define FUSE_UNIONFS_NAME "unionfs"
#define FUSE_UNIONFS_ARGS_FILL_WRITE(argc_p, argv_p, mntfs, mntpoint) \
    *argv_p = malloc(sizeof(char*) * 6);                                \
    *(argc_p) = 0;                                                      \
    (*(argv_p))[(*argc_p)++] = strdup( "unionfs");                      \
    (*(argv_p))[(*argc_p)++] = strdup( "-o");                           \
    (*(argv_p))[(*argc_p)++] = strdup( "cow");                          \
    (*(argv_p))[(*argc_p)++] = strdup (mntfs);                          \
    (*(argv_p))[(*argc_p)++] = strdup (mntpoint);                       \
    (*(argv_p))[(*argc_p)] = NULL;

#define FUSE_UNIONFS_ARGS_FILL_RONLY(argc_p, argv_p, mntfs, mntpoint)   \
    *argv_p = malloc(sizeof(char*) * 6);                                \
    *(argc_p) = 0;                                                      \
    (*(argv_p))[(*argc_p)++] = strdup( "unionfs");                      \
    (*(argv_p))[(*argc_p)++] = strdup( "-o");                           \
    (*(argv_p))[(*argc_p)++] = strdup( "cow");                          \
    (*(argv_p))[(*argc_p)++] = strdup (mntfs);                          \
    (*(argv_p))[(*argc_p)++] = strdup (mntpoint);                       \
    (*(argv_p))[(*argc_p)] = NULL;

#endif /*__UNIONFS_FUSE_H__*/
