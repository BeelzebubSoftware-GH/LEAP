# Rule to compile leap.c and link with leap_run.o to create the executable
leap: compile_py leap.c leap_run.o leap_functions.o headers/leap_header.h
	gcc leap.c leap_run.o leap_functions.o -o leap  # Link leap.c with leap_run.o to create the leap executable

# Rule to compile leap_run.c into leap_run.o
leap_run.o: leap_run.c headers/leap_header.h
	gcc -c leap_run.c -o leap_run.o  # Compile leap_run.c to leap_run.o

# Rule to compile leap_functions.c into leap_functions.o
leap_functions.o: leap_functions.c headers/leap_header.h
	gcc -c leap_functions.c -o leap_functions.o  # Compile leap_run.c to leap_run.o

# Rule to compile Python files to .pyc bytecode
compile_py:
	./.venv/bin/python3 -m compileall

# Rule to clean up the generated files
clear:
	rm -f leap leap_run.o leap_functions.o  # Delete the executable and the object files
	rm -rf __pycache__ # Delete the Python bytecode files
