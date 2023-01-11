# minishell42

This programm is mini version of bash. It was done by ashotmsryan and Vardnyan-Hovo.
<br>Don't judge it too strict, it is done for learning purpose

<h2>HERE IS HOW TO START AND RUN THE PROGRAM</h2><br>
<hr>
step 1- clone it on your device (MAC OS, Linux-kali(the others are not tested)).<br>

step 2- open the folder and run the following command on your concol<br>
```
make readline
```
This is doing 'make' and installs the last version of readline library, files can be dedected in "radline-master" and "ashhov-readline" folders.
step 3- run the following command<br>
```
make
```
it would create object files and the program "minishell" also,<br>
you can also run <br>
```
make clean
```
which delets all the object files, but the program would not be eliminated<br>
```
make fclean
```
this will delete all the object files and the program also<br>
```
make re
```
will run 'make fclean' and 'make' together.<br>
step 4- run './minishell' to execute the program (arguments do not play any role)<br>

<h2>WHAT IS WORKING<br></h2>
<hr>
1)signals<br>
    ......ctrl-C, ctrl-D and ctrl-\<br>
2)commands<br>
    ......all comands which are in $PATH<br>
    ......builtins such as env, cd, pwd, export ...<br>
3)redirections<br>
    ......<<, <, >, >><br>
4)works with multiple '|'<br>
                    
                    ENJOY IT (^_^)
