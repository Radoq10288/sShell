#!/bin/bash

# Check if makefile is for linux or for windows
if [ ! -f "Makefile_Win" -a ! -f "Makefile_Linux" ]; then

	if [ -f "Makefile" ]; then
		echo "The Makefile is not known if it's configured for Windows or Linux."
	else
		echo "No Makefile is available."
	fi
	
elif [ -f "Makefile_Win" -a ! -f "Makefile_Linux" -a ! -f "Makefile" ]; then
	echo "Only Makefile_Win is available."
	
elif [ -f "Makefile_Win" -a -f "Makefile_Linux" ]; then
	echo "Rename Makefile_Linux to Makefile"
	mv "Makefile_Linux" "Makefile"
	
else

	if [ -f "Makefile_Win" -a -f "Makefile" ]; then
		# Clear the screen
		clear

		echo ""
		echo "---------------Clean directory------------------"
		# Clean the current directory
		make clean

		echo ""
		echo ""
		echo "-----------------Build Files--------------------"
		# Build project
		make sShell

		echo ""
		echo ""
		echo "-----------------Run Program--------------------"
		echo ""

		# Run the program
		./sShell

		echo ""
		echo ""
		
	else
		# If Makefile for windows is in use
		echo "Rename Makefile to Makefile_Win."
		mv "Makefile" "Makefile_Win"
		
		echo "Rename Makefile_Linux to Makefile."
		mv "Makefile_Linux" "Makefile"
	fi

fi



