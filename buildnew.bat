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
cmake %cd% -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=RelWithDebInfo

cls
nmake

if %ERRORLEVEL% EQU 0 (
    echo [42mIsle Built!![0m
) else (
	if %ERRORLEVEL% EQU 1 (
		echo [42mIsle Not Built - Incomplete Build[0m
	) else (
		if %ERRORLEVEL% EQU 2 (
			echo [42mIsle Not Built - Program Error[0m
		) else (
			if %ERRORLEVEL% EQU 4 (
				echo [42mIsle Not Built - Out of Memory[0m
			) else (
				if %ERRORLEVEL% EQU 255 (
					echo [42mIsle Not Built - Target not up to date[0m
				)
			)
		)
	)
)

echo Copying game dependencies into build folder...
xcopy /s "%cd%\deps" "%cd%\build"
pause