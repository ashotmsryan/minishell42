# minishell42

This programm is mini version of bash. It was done by ashotmsryan and Vardnyan-Hovo.
Don't judge it too strict, it is done for learning purpose

HERE IS HOW TO START AND RUN THE PROGRAM
<br>
step 1- clone it on your device (MAC OS, Linux-kali(the others are not tested)).
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

        'make'
<br>
        it would create object files and the program "minishell" also,
        you can also run 
        'make clean'
        which delets all the object files, but the program would not be eliminated
        'make fclean'
        this will delete all the object files and the program also
        'make re'
        will run 'make fclean' and 'make' together.
step 4- run './minishell' to execute the program (arguments do not play any role)

WHAT IS WORKING
>>> signals
    ctrl-C, ctrl-D and ctrl-\
>>> commands
    all comands which are in $PATH
    builtins such as env, cd, pwd, export ...
>>> redirections
    <<, <, >, >>
>>>works with multiple '|'
                                      ENJOY IT (^_^)
