import os

CC      = "gcc"
LD      = "ld"

OUTPUT  = "dash"

CFLAGS  = "-DHAVE_CONFIG_H -Isrc -include config.h -DSHELL -ffreestanding -fno-exceptions -m32 -Ilocal -Iprofan_zlib -nostdinc -fno-stack-protector"
LDFLAGS = "-nostdlib -T link.ld -z max-page-size=0x1000 -L/home/pf4/Documents/GitHub/profanOS/out/zlibs/ -lc"

OBJDIR  = "build"
SRCDIR  = ["src", "src/bltin"]

def execute_command(cmd):
    print(cmd)
    rcode = os.system(cmd)
    if rcode == 0: return
    print(f"Command failed with exit code {rcode}")
    exit(rcode if rcode < 256 else 1)

def compile_file(src, dir):
    obj = os.path.join(OBJDIR, f"{os.path.splitext(src)[0]}.o")
    cmd = f"{CC} -c {os.path.join(dir, src)} -o {obj} {CFLAGS}"
    execute_command(cmd)
    return obj

def link_files(entry, objs, output = OUTPUT):
    execute_command(f"{LD} {LDFLAGS} -o {output}.elf {entry} {' '.join(objs)} libtcc.a")

def main():
    execute_command(f"mkdir -p {OBJDIR}")

    objs = []
    for dir in SRCDIR:
        for file in os.listdir(dir):
            if file.endswith(".c"):
                objs.append(compile_file(file, dir))

    objs.append(compile_file("bordel.c", "."))
    entry = compile_file("entry.c", ".")

    link_files(entry, objs)

if __name__ == "__main__":
    main()
