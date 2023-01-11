# minishell42

This programm is mini version of bash. It was done by ashotmsryan and Vardnyan-Hovo.
<br>Don't judge it too strict, it is done for learning purpose

HERE IS HOW TO START AND RUN THE PROGRAM
<br>
<p>   step 1- clone it on your device (MAC OS, Linux-kali(the others are not tested)).
</p>
<br>
step 2- open the folder and run the following command on your concol
<br>
        'make readline'
<br>
        this is doing 'make' and installs the last version of readline library,
<br>
        files can be dedected in "radline-master" and "ashhov-readline" folders.
<br>
step 3- run the following command
<br>
        'make'
<br>
        it would create object files and the program "minishell" also,
<br>
        you can also run 
<br>
        'make clean'<br>
         which delets all the object files, but the program would not be eliminated<br>
        'make fclean'<br>
        this will delete all the object files and the program also<br>
        'make re'<br>
        will run 'make fclean' and 'make' together.<br>
step 4- run './minishell' to execute the program (arguments do not play any role)<br>

WHAT IS WORKING<br>
>>> signals<br>
    ctrl-C, ctrl-D and ctrl-\<br>
>>> commands<br>
    all comands which are in $PATH<br>
    builtins such as env, cd, pwd, export ...<br>
>>> redirections<br>
    <<, <, >, >><br>
>>>works with multiple '|'<br>
                                      ENJOY IT (^_^)
