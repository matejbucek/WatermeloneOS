x86_64_cpp_source_files := $(shell find Kernel -name *.cpp)
x86_64_cpp_object_files := $(patsubst Kernel/%.cpp, build/x86_64/Kernel/%.o, $(x86_64_cpp_source_files))

x86_64_utils_cpp_source_files := $(shell find Utils -name *.cpp)
x86_64_utils_cpp_object_files := $(patsubst Utils/%.cpp, build/x86_64/Utils/%.o, $(x86_64_utils_cpp_source_files))

x86_64_asm_source_files := $(shell find Kernel/Arch/i386/Boot -name *.asm)
x86_64_asm_object_files := $(patsubst Kernel/Arch/i386/Boot/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

x86_64_object_files := $(x86_64_utils_cpp_object_files) $(x86_64_cpp_object_files) $(x86_64_asm_object_files)

$(x86_64_cpp_object_files): build/x86_64/Kernel/%.o : Kernel/%.cpp
	mkdir -p $(dir $@) && \
	gcc -c -march=x86-64 -I . -std=c++11 $(patsubst build/x86_64/Kernel/%.o, Kernel/%.cpp, $@) -o $@

$(x86_64_utils_cpp_object_files): build/x86_64/Utils/%.o : Utils/%.cpp
	mkdir -p $(dir $@) && \
	gcc -c -march=x86-64 -I . -std=c++11 $(patsubst build/x86_64/Utils/%.o, Utils/%.cpp, $@) -o $@

$(x86_64_asm_object_files): build/x86_64/%.o : Kernel/Arch/i386/Boot/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86_64/%.o, Kernel/Arch/i386/Boot/%.asm, $@) -o $@

.PHONY: build-x86_64
build-x86_64: $(x86_64_object_files)
	mkdir -p dist/x86_64 && \
	ld -o dist/x86_64/kernel.bin -n -T targets/x86_64/linker.ld $(x86_64_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso
.KOKOT: clear
clear:
	rm -rf build/x86_64/*