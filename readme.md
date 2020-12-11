# sShell<br /><br />


## About
sShell (simple Shell) - a simple project to teach myself to build a<br />
shell.<br /><br />

## How to build
To build the program:<br />
- **In Windows**<br />
	- If using command prompt, use build.bat.<br />
	- If using cygwin terminal or Msys of MinGW, use build.sh.<br />
	
__Note:__ Makefile generates debug build only.<br /><br />

## Supported Commands
Currently, sShell support 'cd' (change directory) command. Please<br />
see below the two arguments.<br />
- **".."** - (two dots) to move back to previous directory.<br />
- __"\<directory name\>"__ or __"\<absolute directory location\>"__ - sets<br />
  the current directory to the specified directory name or absolute<br />
  directory location.<br />

__Note:__
- To know the current directory location, just type 'cd' without any<br />
arguments.
- Currently, 'cd' command only works on windows. Support for linux<br />
  will be added in future.




