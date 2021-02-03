#!/bin/bash
sudo docker run --rm -it -v $(pwd):/root/env --entrypoint buildenv/dockerBuild.sh watermelonos-buildenv && qemu-system-x86_64 -s -qmp tcp:localhost:4444,server,nowait -serial stdio -cdrom dist/x86_64/kernel.iso