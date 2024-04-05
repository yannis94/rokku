# rokku

Rokku (lock in Japanese) - is a TUI program to generate passwords / passphrase. This is a demo project.

## Getting started

```bash
# Build program (you need gcc install)
make build

# run program
./rokku
```

## Custom

You can change the words.txt file as your wish to have your own custom words.

## TO DO

[ ] cli flags
[ ] make install (build and config for global use)

### cli flags

- --password (-l letter | -d digit | -c special chars)
- --passphrase (-w words)
- -h (help)

### make install

The idea here is to build globally. Building the binary, copy to $PATH, creating a dir in _.local/rokku_ for example. Copy words.txt to .local/rokku...
