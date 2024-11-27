# LEAP – Linux Executable Archive Program beta O.2
**_Warning:_ LEAP is currently under development, so it may not work as it should. If you encounter any bugs, feel free to report!**

## Compiling the source code
LEAP is open-source software. Because it's not a big program, it's shipped as source only. To compile this source into an executable file, type `make` in the Terminal and then you can use `./leap <command>`. To delete the binary files, type `make clear`.

## Commands
### `leap run [flags] <package>`
Opens a LEAP package (usually with the _.leap_ extension), extracts its contents to the `.leapbuffer` directory and runs the file stated in `metadata.json`. Every execution of LEAP clears `.leapbuffer`.

## Versions
### Beta 0.1
* Added `leap run`
### Beta 0.2
* Added support for the `--silent` flag.