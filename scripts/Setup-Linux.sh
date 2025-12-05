cd ..


premake5 gmake
bear -- make clean all
ln -s compile_commands.json ./SnakeGame/src/
