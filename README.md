# CS-Project-3


Project Summary:
The Corner Grocer Item Tracker project was designed to track the frequency of grocery items purchased throughout the day. It reads items from an input file, stores their purchase counts using a map, and allows users to search for specific item frequencies, display all frequencies, and visualize the data with a histogram.

What I Did Well:

    Clean and organized class design.

    Strong input validation to prevent crashes.

    Created a user-friendly menu for easy navigation.

    Successfully generated a backup file (frequency.dat) for data persistence.

    Provided clear and visually helpful histogram output.

Areas for Improvement:

    Make item searches case-insensitive to improve user experience.

    Add more robust exception handling for file operations.

    Allow users to input custom filenames instead of using a hardcoded file.

    Consider using unordered maps for faster data lookups in larger datasets.

    These changes would make the program more efficient, secure, and adaptable.

Most Challenging Parts:

    Validating user input to handle incorrect entries without crashing.

    Formatting the histogram display neatly and aligning the output.

    Overcame these challenges using input buffer management (cin.clear(), cin.ignore()) and output formatting tools like setw().

    Resources used included C++ documentation, online tutorials, and course materials.

Transferable Skills:

    File reading and writing.

    Working with data structures like maps.

    Building modular, object-oriented programs.

    Implementing effective input validation.

    Creating user-friendly console interfaces.

How I Made the Program Maintainable:

    Used clear, descriptive function names.

    Applied consistent formatting and indentation throughout the code.

    Designed the program with separation of concerns (file handling, user interaction, and data processing are clearly separated).

    Developed a modular class structure that can easily be updated or expanded.
