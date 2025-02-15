# Dash port for profanOS

This is a port of the [Dash](https://git.kernel.org/pub/scm/utils/dash/dash.git)
[v0.5.11.5](https://git.kernel.org/pub/scm/utils/dash/dash.git/tag/?h=v0.5.11.5)
shell for [profanOS](https://github.com/elydre/profanOS) to have a POSIX
compliant shell.

## Building

```sh
# in your profanOS, build the disk
cd path/to/profanOS
make clean disk

# go to dash port
cd path/to/dash

# build dash
python build.py /path/to/profanOS

# copy the binary to profanOS filesystem
cp dash path/to/profanOS/out/zapps/h/
```

*I'm not the author of the original Dash shell, I just ported it to profanOS.*
