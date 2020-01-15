; Generated NSIS script file (generated by makensitemplate.phtml 0.20)
; by 63.48.69.245 on Sep 19 01 @ 15:09

; NOTE: this .NSI script is designed for NSIS v1.3+

Name "Small Device C Compiler"
OutFile "c:\temp\sdcc-2.3.0-installer.exe"

; Some default compiler settings (uncomment and change at will):
; SetCompress auto ; (can be off or force)
; SetDatablockOptimize on ; (can be off)
; CRCCheck on ; (can be off)
AutoCloseWindow true ; (can be true for the window go away automatically at end)
; ShowInstDetails hide ; (can be show to have them shown, or nevershow to disable)
; SetDateSave off ; (can be on to have files restored to their orginal date)

LicenseText "SDCC is licensed under the GNU Public License"
LicenseData "LICENSE.txt"

InstallDir "c:\sdcc"
InstallDirRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Small Device C Compiler Group\Small Device C Compiler" ""
DirShow show
DirText "Choose the directory to install SDCC into.  Currently only c:\sdcc is supported."

Section "" ; (default section)
SetOutPath "$INSTDIR"
; add files / whatever that need to be installed here.
File /r bin
File /r share
File /r doc
File README.txt
File INSTALL.txt
File LICENSE.txt
WriteRegStr HKEY_LOCAL_MACHINE "SOFTWARE\Small Device C Compiler Group\Small Device C Compiler" "" "$INSTDIR"
CreateDirectory "$SMPROGRAMS\Small Device C Compiler"
CreateShortCut "$SMPROGRAMS\Small Device C Compiler\README.lnk" $INSTDIR\README.txt
CreateShortCut "$SMPROGRAMS\Small Device C Compiler\INSTALL.lnk" $INSTDIR\INSTALL.txt
CreateShortCut "$SMPROGRAMS\Small Device C Compiler\LICENSE.lnk" $INSTDIR\LICENSE.txt
CreateShortCut "$SMPROGRAMS\Small Device C Compiler\Users Guide.lnk" $INSTDIR\share\doc\sdcc\sdccman.html\index.html
ExecShell open $INSTDIR\README.txt
SectionEnd ; end of default section

; eof
