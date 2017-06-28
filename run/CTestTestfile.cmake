# CMake generated Testfile for 
# Source directory: /Users/luisfernando/Projetos/servidor-so
# Build directory: /Users/luisfernando/Projetos/servidor-so/run
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(crow_test "/Users/luisfernando/Projetos/servidor-so/run/tests/unittest")
add_test(template_test "/Users/luisfernando/Projetos/servidor-so/run/tests/template/test.py")
set_tests_properties(template_test PROPERTIES  WORKING_DIRECTORY "/Users/luisfernando/Projetos/servidor-so/run/tests/template")
subdirs("cpp")
