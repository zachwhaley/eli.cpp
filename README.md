# eli (short for Eliana)

A bare bones text editor written in C++

Check out [eli.c](https://github.com/zachwhaley/eli.c).  It's the same thing written in C

## Libraries

[ncurses](https://www.gnu.org/software/ncurses/ncurses.html)

```bash
$ yum install ncurses ncurses-libs ncurses-static
```

[G++](http://gcc.gnu.org/)

```bash
$ yum install gcc-c++
```

## What it Does

Displays a files content on the screen.

Move around with the arrow keys.

Type some things, and watch them appear.

Use <kbd>Ctrl-w</kbd> to save and <kbd>Ctrl-q</kbd> to quit.

## How to Use it

```bash
$ make
$ ./eli somefile
```
