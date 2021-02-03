# WatermelonOS

This is an open source operating system made for education purposes.

### Requirements

You need to have Docker and QEMU installed.

### Build environment

1. Build docker cross-compile image.

```
docker build -t watermeloneos-buildenv buildenv
```

2. Build and launch kernel.

```
buildenv/build.sh
```


### Debugging

You can use GDB, QEMU starts with default port (1234) opened.

```
    gdb
    target remote localhost:1234
```