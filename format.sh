find src tests -name \*.c -exec clang-format -i {} \;
find src tests -name \*.h -exec clang-format -i {} \;
find src tests -name \*.cc -exec clang-format -i {} \;
find src tests -name \*.cpp -exec clang-format -i {} \;
find src tests -name \*.inc  -exec clang-format -i {} \;

