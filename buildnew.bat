@echo off
C:
cd "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build"
call vcvars32.bat x86

D:

if exist "build\" (
    rmdir /s /q "build"
)

mkdir "build"
cd build
cmake .. -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=RelWithDebInfo

cls
nmake

if %ERRORLEVEL% EQU 0 (
    echo [42mIsle Built Successfully!![0m
	goto deps
) else (
	if %ERRORLEVEL% EQU 1 (
		echo [41mIsle Not Built - Incomplete Build[0m
		goto done
	) else (
		if %ERRORLEVEL% EQU 2 (
			echo [41mIsle Not Built - Program Error[0m
			goto done
		) else (
			if %ERRORLEVEL% EQU 4 (
				echo [41mIsle Not Built - Out of Memory[0m
				goto done
			) else (
				if %ERRORLEVEL% EQU 255 (
					echo [41mIsle Not Built - Target not up to date[0m
					goto done
				)
			)
		)
	)
)

:deps
echo Copying game dependencies into build folder...
xcopy /s "..\deps" "..\build" > nul
goto done

:done
echo Build complete