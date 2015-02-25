CFLAGS += -Wall
CPPFLAGS += $(shell PKG_CONFIG_PATH=$(PREFIX)/x86_64-nacl/lib/pkgconfig pkg-config --cflags fuse)
CPPFLAGS += -DFUSE_USE_VERSION=26

CPPFLAGS += -DLIBC_XATTR # glibc nowadays includes xattr
# CPPFLAGS += -DLIBATTR_XATTR # define this to libattr xattr include

# CPPFLAGS += -DDISABLE_XATTR # disable xattr support
# CPPFLAGS += -DDISABLE_AT    # disable *at function support

LDFLAGS += 

LIB = $(shell pkg-config --libs fuse) -lpthread

HASHTABLE_OBJ = hashtable.o hashtable_itr.o
UNIONFS_OBJ = unionfs.o opts.o debug.o findbranch.o readdir.o \
		general.o unlink.o rmdir.o cow.o cow_utils.o string.o \
		usyslog.o
UNIONFSCTL_OBJ = unionfsctl.o


all: libunionfs.a

unionfs: $(UNIONFS_OBJ) $(HASHTABLE_OBJ) uioctl.h version.h
	$(CC) $(LDFLAGS) -o $@ $(UNIONFS_OBJ) $(HASHTABLE_OBJ) $(LIB)

unionfsctl: $(UNIONFSCTL_OBJ) uioctl.h version.h
	$(CC) $(LDFLAGS) -o $@ $(UNIONFSCTL_OBJ)

libunionfs.a: $(UNIONFS_OBJ) $(HASHTABLE_OBJ) uioctl.h version.h
	$(AR) rcs $@ $(UNIONFS_OBJ) $(HASHTABLE_OBJ)

install: libunionfs.a
	install -m 0644 ../fuse/unionfs.h $(PREFIX)/x86_64-nacl/include/fuse/unionfs.h
	install -m 0644 libunionfs.a $(PREFIX)/x86_64-nacl/lib

clean:
	rm -f unionfs
	rm -f unionfsctl
	rm -f *.o *.a
