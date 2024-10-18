# MicroVim 4.1
MicroVim is a basic text editor written in scratch from C. There is no real big benefit to it; I just didn't want to learn how to use Vim or a super complicated editor, so I implemented the basics of it myself.

## Features
- Two modes: `-- NORMAL --` and `-- INSERT --`
- Basic I/O
- Command line ``:``

## Roadmap
- [X] File I/O
- [X] Arrow navigation (a cursor)
- [X] Keyboard shortcuts
- [X] Modes
- [X] Lua plugins ``WIP``
- [ ] Configurations
- [ ] Commands

## Install
You can install MicroVim over GNU Make:
```bash
make microvim # make the editor
make install # installs to /usr/local/bin (Linux/OSX only)

# Here is how to run microvim
microvim file.txt

# These aliases are also created during install. You can remove them from your ~/.bashrc
mvim file.txt
mim file.txt
```

## License
MicroVim is licensed under GNU LGPL v2.1. Read it [here](/LICENSE).
