## _Convert VBS file to EXE_

VBScript to executable for Windows 10

-------------------------------------------------------------------

## _Installation_

vbs2exe requires [GCC](https://sourceforge.net/projects/mingw/) version 6.3.0+ to run.

After gcc installation, if you are building the source code run the _RunMe.bat_ file, otherwise read _usage_ section.

-------------------------------------------------------------------

# _Usage_

Open cmd into the same directory of the vbs2exe.exe file and type:

```sh
vbs2exe <filename>
```

Where &lt;filename&gt; the name of the VBS file you would like to convert into the EXE.
The file extension is optional. Name must be 20 characters long max.

Make sure the VBS file you want to convert is in the same directorry as the vbs2exe.exe file.
The output EXE file will be placed into this directory with the exact same name as the original VBS file.

_Attention! wscripts only!_

-------------------------------------------------------------------

# _Example_

```sh
vbs2exe whatever
vbs2exe whatever.vbs
vbs2exe.exe whatever
vbs2exe.exe whatever.vbs
```

The output on all those cases will be whatever.exe 

-------------------------------------------------------------------

## _License_

[MIT](https://github.com/eimon96/vbs2exe/blob/main/LICENSE)

-------------------------------------------------------------------

 @author: eimon 😷
