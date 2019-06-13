# SO-Shell
A Shell developed for Operative Systems

# Commands (Built-In)

   **• help** -> It shows a list of built-in commands on standard output;
   
   **• sair/exit/quit/leave NUMBER** -> It shutdowns the program after X seconds (if you just write "quit", it will be shutdown after 3 seconds;
   
   **• cd** -> It changes your current directory;
   
   **• 42** -> It shows the explanation of number 42;
   
   **• aviso message number** -> Shows an warning message after NUMBER seconds;
   
   **• avisoth message number** -> Shows an warning message after NUMBER seconds (by using threads);
   
   **• PS1=name** -> It changes the default prefix to a word that you want to choose (if you write {default} it will give the default prefix;
   
   **• calc number operation number** -> It calculates an operation between two real numbers;
   
   **• bits number operation number** -> It calculates a binary operation between two integer numbers;
   
   **• quemsoueu** -> It calls the system("id") function;
   
   **• socp source destiny** -> It copies the content of FILE1 to FILE2;
   
   **• socpth source destiny** -> It copies the content of FILE1 to FILE2 (using threads);
   
   **• jpg (or jpeg) file** -> It checks if FILE1 is a JPEG file;
   
   **• obterinfo** -> Shows a simple print with shell information
   
   **• blackjack** -> Starts a blackjack game
   
   **• tictactoe** -> Starts a tictactoe game

# Redirects, Pipes, Background/Foreground and Threads

This program also has redirect support for non-builtin commands (e.g: ls), also as Pipe and Backgroud executes support;

**Supported Redirects:**

    Input (<);
    Append Output (>>);
    Output (>);
    Error Output (2>);
