# Main.c contents
The main file begins by including stdio.h and headers/data.h
After this, 3 global variables get defined.
- currentlyNotClicking  (This is for telling threads whether or not they should be clicking at the moment
- clickerThreadCount    (The amount of threads that should be created for clicking, this is determined by the logical processer count)
- cps                   (The amount of CPS to click at)

After there, the main function begins

# Main function contents
The main function starts by setting the title of the console to "XtremeAutoClicker "VERSION (version being defined in data.h)
Then the next line gets a Window Handle for the console

After that, Quick Edit is disabled (Quick edit being disabled is because this only pauses the main thread, but nothing else)

Then, variables for the logical processer count and maximum recommended CPS are made, and set to their corresponding values

Afterwards, a variable is defined for getting the CPS from the user, which is then decreased to get higher accuracy
