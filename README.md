# MAKEFILE COMMANDS

# First build
make

# Clean and rebuild
make clean
make

# Run the program
make run

# Debug with GDB
make debug

# Check for memory leaks
make valgrind

# DOCKERFILE

# 1. Build the image
docker build -t taskforge .

# 2. Run tests
docker run --rm taskforge

# 3. Check for memory leaks
docker run --rm taskforge valgrind --leak-check=full --show-leak-kinds=all ./taskforge

# 4. Debug if needed
docker run -it --rm taskforge gdb ./taskforge

# 5. Clean up
docker system prune