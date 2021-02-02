source_dir = src
build_dir = build
includes_dir = headers

# include any new source file here, or just add it inside the ./src folder
source_files = main.cpp $(source_dir)/*.cpp

# build file name, default is app
build_file = app

# compiler, if you use clang change here
cc = g++

# compiler flags
flags = -lsfml-graphics -lsfml-window -lsfml-system

build_program:
	@$(cc) $(source_files) -o $(build_dir)/$(build_file) $(flags)

# $ make run -> to run the executable
run:  
	@cd $(build_dir) && ./$(build_file)

reset:
	rm -rf $(build_dir)/*


