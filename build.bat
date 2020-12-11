@echo off

rem Check if makefile is for linux or for windows
if not exist "Makefile_Linux" (

	if not exist "Makefile_Win" (
	
		if exist "Makefile" (
			echo The Makefile is not known if it's configured for Windows or Linux.
			echo.
		) else (
			echo No Makefile is available.
			echo.
		)
		
	) else (
		goto ELSEOPTION
	)

) else (

	if exist "Makefile_Linux" (
	
		if not exist "Makefile_Win" (
	
			if not exist "Makefile" (
				echo Only Makefile_Linux is available.
				echo.
			) else (
				goto ELSEOPTION
			)

		) else (
		
			if exist "Makefile_Win" (

					
				if exist "Makefile_Linux" (
					echo Rename Makefile_Win to Makefile.
					echo.
					rename Makefile_Win Makefile
				) else (
					goto ELSEOPTION
				)

			) else (
				goto ELSEOPTION
			)

		)

	) else (
		
		:ELSEOPTION
		if exist "Makefile_Linux" (
	
			if exist "Makefile" (
				rem Clear the screen
				cls

				echo.
				echo ---------------Clean directory------------------
				rem Clean the current directory
				mingw32-make clean

				echo.
				echo.
				echo -----------------Build Files--------------------
				rem Build project
				mingw32-make sShell

				echo.
				echo.
				echo -----------------Run Program--------------------
				echo.

				rem Run the program
				sShell

				echo.
				echo.
			)

		) else (
			rem If Makefile for linux is in use
			echo Rename Makefile to Makefile_Linux.
			rename Makefile Makefile_Linux

			echo Rename Makefile_Win to Makefile.
			rename Makefile_Win Makefile
			
			echo.
		)

	)

)



