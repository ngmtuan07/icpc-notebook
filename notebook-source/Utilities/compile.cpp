function cm() {
    echo "Compiling $1.cpp..."
    echo "g++ -std=c++20 -O2 $1.cpp -o $1"
    g++ -std=c++20 -O2 $1.cpp -o $1
}